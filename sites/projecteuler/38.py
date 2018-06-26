fat = [1]
def fato(n):
	tam = len(fat)
	if(tam <= n):
		for a in range(tam, n+1):
			fat.append(fat[a-1]*a) 

	return fat[n]
pan = []

aux=[1,1,1,1,1,1,1,1,1]

cont = 0
fa = fato(9)
while(cont < fa):
	n = 0
	u = [1,2,3,4,5,6,7,8,9]
	for i in range(0,9):
		n+=u[aux[i]-1]*10**(8-i)
		u.remove(u[aux[i]-1])
	
	pan.append(n)
	cont+=1
	for a in range(0,9):
		aux[a] = ((cont//fato(8-a))%(9-a))+1

dig = 1

mpan = 0

while(dig <= 5):
	print(dig)
	ini = mpan//10**(9-dig)
	while(ini < 10**dig):
		ad=[str(ini)]
		for n in range(2,(9//dig)+2):
			for k in str(ini*n):
				ad.append(k)
			nn = 0
			tamad = len(ad)
			for kk in range(0,tamad):
				nn += int(ad[kk])*10**(tamad-1-kk)
			if(nn in pan):
				mpan = max(nn,mpan)
		ini+=1
	dig+=1
	
print(mpan)