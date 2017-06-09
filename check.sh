#!/bin/bash
set -e                                  # stops script on error (such as compilation error)
g++ $1 -O2 -Wall -std=c++11 -g          # $1 contains first command-line argument

for i in in*
do
    j=$(echo $i | tail -c +3)
    ./a.out < $i > "out$j"
    if [ -z "$(diff -B out$j ans$j)" ]  # -z -> true if string is empty
    then
        echo "Test $j: ok"
    else
        echo "Test $j: wa (or presentation error)"

        echo "Correct answer:"
        cat "ans$j"
        echo ""
        echo "Author's answer:"
        cat "out$j"
        echo ""
    fi
done