# About the scripts

## cfparser.py
Script to parse Codeforces tests

How to use: Run "python cfparser.py [contest id] [problem letter]". Then, the input will be parsed and stored in files in1, in2, in3..., and the expected output will be parsed and stored in files ans1, ans2, ans3...


## check 
Script to run tests in multiple files
- You can run 1 test at a time
- In general, better with Codeforces contests (because you can combine with cfparser.py)

How to use: Run "bash check [file name] [number of tests]", and the script will run the solution giving the inputs in files in1, in2, etc, redirect the output to files out1, out2, etc, and compare these files with ans1, ans2, etc (expected outputs).


## check.py
Script to run tests in a single file
- Easier to put custom tests
- Simpler/Folder less poluted (less files)
- In general, better with non-Codeforces contests (because it's simpler, once you don't have cfparser.py)

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

Then, run "python check.py [file name]".
