ans = 0
const = 101

for i in range (1,const):
	for j in range (1,const):
		sum = 0
		a = str(i**j)
		for ss in a:
			sum += int(ss)
		ans = max(ans, sum)

print(ans)