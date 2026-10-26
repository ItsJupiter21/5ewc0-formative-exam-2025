"""Black-box tests transcribed from the 2025 Banking formative exam, published cases 0 through 9."""

import json
from pathlib import Path
import subprocess
import unittest


ROOT = Path(__file__).resolve().parents[1]
CASES = json.loads((ROOT / "tests" / "cases.json").read_text())


def normalize(output):
    """Ignore all whitespace and normalize typographic quotes."""
    output = output.replace("\u2019", "'").replace("\u2018", "'")
    return "".join(output.split())


class TestBanking(unittest.TestCase):
    """Each case launches a fresh process and supplies its complete stdin."""


def failure_report(case, actual, stderr=""):
    def text(value):
        if isinstance(value, bytes):
            return value.decode(errors="replace")
        return value or ""

    return (
        f"Case {case['case']}: {case['description']}\n\n"
        f"--- Input ---\n{case['stdin']}\n"
        f"--- Expected output ---\n{case['stdout']}\n"
        f"--- Actual output ---\n{text(actual)}\n"
        f"--- Stderr ---\n{text(stderr)}"
    )


def make_test(case):
    def test(self):
        program = ROOT / "build" / "main"
        if not program.is_file():
            self.fail("Build the program first: make\n\n" + failure_report(
                case, "(program was not run)"
            ))
        try:
            result = subprocess.run(
                [str(program)],
                input=case["stdin"],
                capture_output=True,
                text=True,
                timeout=3,
                cwd=ROOT,
            )
        except subprocess.TimeoutExpired as error:
            self.fail(
                "Program did not exit within 3 seconds; check command handling.\n\n"
                + failure_report(case, error.stdout, error.stderr)
            )
        if result.returncode != 0:
            self.fail(
                f"Program exited with status {result.returncode}.\n\n"
                + failure_report(case, result.stdout, result.stderr)
            )
        if normalize(result.stdout) != normalize(case["stdout"]):
            self.fail(failure_report(case, result.stdout, result.stderr))

    test.__doc__ = case["description"]
    return test


for case in CASES:
    setattr(TestBanking, f"test_case_{case['case']}", make_test(case))


if __name__ == "__main__":
    unittest.main()
