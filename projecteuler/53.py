v = []
const = 101

def main():
	v.append([1,0])

	for i in range(1,const):
		linha = [1]
		for j in range(1,i+1):
			linha.append(v[i-1][j-1] + v[i-1][j])
		linha.append(0)

		v.append(linha)


	count = 0
	for i in range(0,const):
		for j in range(0,i+1):
			if v[i][j] > 1000000:
				count += 1

	print(count)

main()