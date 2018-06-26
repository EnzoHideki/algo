import math

n = 1
count = 1
with open("input.txt","r") as f:
	for linha in f:
		l = linha.split(",")
		l[0] = int(l[0])
		l[1] = int(l[1])

		if count == 1:
			big = l
		elif ((l[1])*math.log(l[0]) > (big[1])*math.log(big[0])):
			big = l
			n = count

		count += 1

print(n)