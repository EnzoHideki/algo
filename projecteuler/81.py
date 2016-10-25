m = []
dp = []

with open("entrada.txt","r") as f:
	for linha in f :
		u = linha.split(',')
		v = []
		for d in u:
			v.append(int(d))

		m.append(v)


for i in range(80):
	u = []
	for j in range(80):
		u.append(-1)
	dp.append(u)


def f(i, j):
	if (i == 79 and j == 79):
		return m[i][j]

	if (i == 79):
		if (dp[i][j] == -1):
			dp[i][j] = m[i][j] + f(i,j+1)
		return dp[i][j]

	if (j == 79):
		if (dp[i][j] == -1):
			dp[i][j] = m[i][j] + f(i+1,j)
		return dp[i][j]

	if (dp[i][j] == -1):
		dp[i][j] = m[i][j] + min(f(i+1,j), f(i,j+1))

	return dp[i][j]

print(f(0,0))