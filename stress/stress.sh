set -e
g++ gen.cpp -Wall -std=c++11 -O2 -o gen
g++ naive.cpp -Wall -std=c++11 -O2 -o naive
g++ $1 -Wall -std=c++11 -O2

i=0
while :
do
	./gen > in
	./a.out < in > out1
	./naive < in > out2

	if diff -q out1 out2; then
		echo "Test $i ok"
	else
		echo "Test $i failed"
		break
	fi

	i=$((i + 1))
done