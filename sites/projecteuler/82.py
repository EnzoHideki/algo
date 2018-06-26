dp = []
m = []

const = 80

for i in range(0,const):
	aux = []
	for j in range(0,const):
		aux.append([-1,-1,-1])
	dp.append(aux)

def f(i,j,k):
	if (dp[i][j][k] == -1):
		if (j == const-1):
			dp[i][j][0] = m[i][j]
			dp[i][j][1] = m[i][j]
			dp[i][j][2] = m[i][j]

		elif (i == 0 and k == 1):
			dp[i][j][k] = m[i][j] + f(i,j+1,0)

		elif (i == 0 and k == 0):
			dp[i][j][k] = m[i][j] + min(f(i,j+1,0), f(i+1,j,-1))

		elif (i == const-1 and k == -1):
			dp[i][j][k] = m[i][j] + f(i,j+1,0)

		elif (i == const-1 and k == 0):
			dp[i][j][k] = m[i][j] + min(f(i,j+1,0), f(i-1,j,1))

		elif (k == 1):
			dp[i][j][k] = m[i][j] + min(f(i,j+1,0), f(i-1,j,1))

		elif (k == 0):
			dp[i][j][k] = m[i][j] + min(f(i,j+1,0), min(f(i-1,j,1), f(i+1,j,-1)))

		elif (k == -1):
			dp[i][j][k] = m[i][j] + min(f(i,j+1,0), f(i+1,j,-1))

	return dp[i][j][k]

def main():
	ans = int(1e18)

	with open("input.txt", "r") as file:
		for line in file:
			aux1 = line.split(",")
			aux2 = []
			for el in aux1:
				aux2.append(int(el))
			m.append(aux2)

	for i in range(0, const):
		ans = min(ans, f(i,0,0))

	print(ans)

main()