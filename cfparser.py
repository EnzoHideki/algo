#!/usr/bin/python2
 
import re
import requests
import sys
 
if len(sys.argv) < 3:
    print("Need contest number and problem")
    sys.exit(0)

def parse_task():
    if (int(sys.argv[1]) > 100000):
        s = requests.get("http://codeforces.com/gym/" + sys.argv[1] + 
                    "/problem/" + sys.argv[2]).text
    else:    
        s = requests.get("http://codeforces.com/contest/" + sys.argv[1] + 
                    "/problem/" + sys.argv[2]).text

    a = re.findall("Input</div><pre>.*?</pre>", s)
    b = re.findall("Output</div><pre>.*?</pre>", s)
 
    if (len(a) == 0):
        print("Something went wrong...")
        sys.exit(0)
 
    assert(len(a) == len(b))

    for i in range(len(a)):
        a[i] = a[i][16:-6].replace('<br />', '\n')
        b[i] = b[i][17:-6].replace('<br />', '\n')
 
    with open("tests", "w") as f:
        for i in range(len(a)):
            print(a[i], end="", file=f)
            print("ans:", file=f)
            print(b[i], end="", file=f)
            print("===", file=f)

    print(len(a), "tests parsed!")

parse_task()