def isP(ss):
	size = len(ss)
	for i in range(0, size):
		if(ss[i] != ss[size-1-i]):
			return False

	return True

count = 0
for i in range (1,10001):
	n = i
	ok = True
	for j in range(0,50):
		n = n + int(str(n)[::-1])
		if isP(str(n)):
			ok = False
			break

	if ok:
		count += 1

print(count)