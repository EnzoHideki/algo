#!/bin/bash
set -e                                  # stops script on error (such as compilation error)
g++ $1 -O2 -Wall -std=c++11 -g

for i in $(seq 1 $2)
do
    ./a.out < "in$i" > "out$i"
    if [ -z "$(diff -B out$i ans$i)" ]  # -z -> true if string is empty
    then
        echo "Test $i: ok"
    else
        echo "Test $i: wa (or presentation error)"

        echo "Correct answer:"
        cat "ans$i"
        echo ""
        echo "Author's answer:"
        cat "out$i"
        echo ""
    fi
done