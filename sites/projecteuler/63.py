ans = 0
for i in range(1,10):
	j = 1
	while (True):
		obj = len(str(i**j)) 
		if (obj == j):
			ans+=1
		elif (obj < j):
			break

		j += 1

print (ans)