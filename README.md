# Banking — Formative exam 2025

C programming practice environment for the 5EWC0 Banking formative exam dated
28 October 2025.

- [Exam in Markdown](EXAM.md): all seven tasks, examples, hints, and ten test cases.
- [Original exam PDF](formative2025.pdf).
- `main.c`: empty file for your solution.
- `starter.c`: optional reconstructed baseline, without task solutions.
- `tests/`: ten published input/output cases and a test runner.

## Getting started

Requirements: a C compiler (GCC or Clang), Make, and Python 3 with `venv`.
No additional Python packages are needed.

From the repository directory:

```sh
make setup             # Create the local .venv
# Optional, before starting your solution:
cp starter.c main.c     # Replaces main.c with the reconstructed baseline
make                   # Compile main.c to build/main
make run               # Run interactively
make test              # Run all 10 published cases
make test CASE=0        # Check the baseline
make test CASE=9        # Check the combined case
make clean             # Remove build outputs and test bytecode; keep .venv
```

No virtual environment activation is necessary: `make test` automatically creates
and uses `.venv/bin/python`. Compilation uses C99 with
`-Wall -Wextra -Werror -g`. For Clang, use `make CC=clang`.
Build/run/test stop with an explanation until `main.c` is nonempty.

## Exam baseline

The exam refers to a separately supplied skeleton that is not included in the
source PDF. `starter.c` is a local reconstruction, not the original skeleton.
It initializes the five balances and bank name, prints the welcome message,
handles `q`, and outputs the final data. Tasks 1–7 are left to implement.
Commands are handled by a `switch` inside a `for (;;)` loop, with a TODO case
for each task. The `q` case prints the final data and returns from `main`.
The reconstruction supplies suitable local signatures for `initializeAccountData`
and `outputAccountData`; their original signatures were not provided.

## Test cases

The cases in `tests/cases.json` are transcribed from the PDF's explicit
**Input / output test cases** section.

| Cases | Task | Behavior |
| --- | --- | --- |
| 0 | Baseline | Quit and output initial data |
| 1 | 1 | Print positive and negative balances |
| 2 | 2 | Deduct a service charge |
| 3 | 3 | Apply tiered interest |
| 4–5 | 4 | Change balances and validate account IDs |
| 6 | 5 | Compute the percentage of debtors |
| 7 | 6 | Remove the bracketed version |
| 8 | 7 | Read a bank name with spaces |
| 9 | 1–7 | Combine all tasks |

Each case starts a fresh process, checks successful exit and complete stdout,
and stops a hung process after three seconds. Input is piped and is not echoed.
The runner ignores whitespace and normalizes curly single quotes. Other text,
punctuation, numeric formatting, and prompt order must match. These are the
published examples, not extra hidden cases.

## Transcription notes

`EXAM.md` preserves the exam's wording, including inconsistencies. The task
examples use `Accounts` in the final data dump, while the explicit test cases
use `Account`. The local tests and reconstructed starter follow `Account`.
PDF layout, page breaks, decorative borders, and QR-code footers are omitted
from the Markdown; the original PDF is included unchanged.
