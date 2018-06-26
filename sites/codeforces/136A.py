n = int(input())

ans = []
v = input().split(' ')

for i in range(n+1):
	ans.append(-1)

for i in range(n):
	ans[int(v[i])] = i+1

for i in range(1,n+1):
	print(ans[i], end = ' ')