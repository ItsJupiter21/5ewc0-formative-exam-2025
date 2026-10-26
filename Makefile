CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Werror -g
PYTHON ?= python3
VENV = .venv
TEST_PYTHON = $(VENV)/bin/python
PROGRAM = build/main

.PHONY: all setup run test clean

all: $(PROGRAM)

setup: $(TEST_PYTHON)

$(TEST_PYTHON):
	$(PYTHON) -m venv $(VENV)

$(PROGRAM): main.c
	@if ! test -s main.c; then \
		echo "main.c is empty. Add your main function before running or testing." >&2; \
		exit 1; \
	fi
	mkdir -p build
	$(CC) $(CFLAGS) main.c -o $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

# Examples: make test; make test CASE=9
test: setup $(PROGRAM)
	$(TEST_PYTHON) -m unittest $(if $(CASE),tests.test_banking.TestBanking.test_case_$(CASE),discover -s tests) -v

clean:
	rm -rf build tests/__pycache__
