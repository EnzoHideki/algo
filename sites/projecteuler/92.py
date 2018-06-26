s1 = {1}
s89 = {89}

ans = 0
for i in range(1,10000000):
	n = i
	while (True):
		if (n in s1 or n in s89):
			break

		s = str(n)
		size = len(s)
		n = 0
		for j in range(0,size):
			n += int(s[j])**2

	if (n in s1):
		s1.add(i)
	else:
		s89.add(i)
		ans += 1

print(ans)