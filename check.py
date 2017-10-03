import os, sys

os.system("g++ " + sys.argv[1] + " -O2 -Wall -std=c++11 -g")

test = 0

lines = []
with open('tests') as inp:
	for lin in inp:
		lines.append(lin)

i = 0
while i < len(lines):
	test += 1

	with open('in', 'w') as file:				
		while lines[i] != "ans:\n":
			file.write(lines[i])
			i += 1

	os.system("./a.out < in > out")

	i += 1

	s = ""
	while lines[i] != "===\n":
		if lines[i] != "\n":
			s += lines[i]

		i += 1

		if (i >= len(lines)):
			break

	i += 1

	with open('out', 'r') as out:
		ans = out.read()

		if (s == ans):
			print "Test " + str(test) + ": ok\n"
		else:
			print "Test " + str(test) + ": wa (or presentation error)"
			print "Correct answer:"
			print s
			print "Author's answer:"
			print ans