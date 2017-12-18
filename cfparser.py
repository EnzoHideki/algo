#!/usr/bin/python2
 
import re
import requests
import sys
 
if len(sys.argv) < 3:
    print "Need contest number and problem"
    sys.exit(0)

def parse_task():
    s = requests.get("http://codeforces.com/contest/" + sys.argv[1] + 
                    "/problem/" + sys.argv[2]).text

    a = re.findall("Input</div><pre>.*?</pre>", s)
    b = re.findall("Output</div><pre>.*?</pre>", s)
 
    if (len(a) == 0):
        print "Something went wrong..."
        sys.exit(0)
 
    assert(len(a) == len(b))

    for i in xrange(len(a)):
        a[i] = a[i][16:-6].replace('<br />', '\n')
        b[i] = b[i][17:-6].replace('<br />', '\n')
 
    for i in xrange(len(a)):
        with open("in" + str(i+1), "w") as f:
            print >> f, a[i]
        with open("ans" + str(i+1), "w") as f:
            print >> f, b[i]

    print len(a), "tests parsed!"

parse_task()