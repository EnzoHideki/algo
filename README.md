# About the scripts

## cfparser.py (need requests module)
Script to parse Codeforces tests

How to use: Run ```python3 cfparser.py [contest id] [problem letter]```. Then, the inputs and outputs will be parsed and stored in file called 'tests' in the following format:

```
(input)
ans:
(expected output)
===
(input)
ans:
(expected output)
===
.
.
.
```

## check.py
Script to run tests in a single file. It uses python 2.

How to use: 

Put the test cases in a file named 'tests' in the following format:

```
(input)
ans:
(expected output)
===
(input)
ans:
(expected output)
===
.
.
.
```

Then, run ```python check.py [file name]```
