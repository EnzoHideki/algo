import math
import time

i = 1

v = []

factors = []

v.append(0)
factors.append(1)

qtd = 0

Q = 4

while(1):
	j = 1
	div = 0

	end = 0

	if(i % 10000 == 0):
		print("i ", i)

	while j <= math.sqrt(i):
		if(i % j == 0 and j != 1):
			div = 1
			v.append(j)

			tmp = i
			s = set([])
			while tmp != 1:
				s.add(v[int(tmp)])
				tmp /= v[int(tmp)]

			factors.append(len(s))

			if(len(s) == Q):
				qtd += 1
				if(qtd == Q):
					print("Answer:", i+1-Q)
					end = 1
			else:
				qtd = 0

			break
		j+=1

	if(end):
		break

	if(div == 0):
		qtd = 0
		v.append(i)
		factors.append(1)

	i+=1