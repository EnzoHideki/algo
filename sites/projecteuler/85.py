diff = int(1e18)

a = 0
b = 0
for m in range(0,1451):
	for n in range(0,1451):
		const = (m*m*n*n + m*m*n + m*n*n + m*n)//4

		if (abs(const - 2000000) < diff):
			diff = abs(const - 2000000)
			a = m
			b = n

print(a*b)