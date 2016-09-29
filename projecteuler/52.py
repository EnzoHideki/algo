pot = 1
cont = 1
ok = False
while(not ok):
	if(cont >= 1.7*10**pot):
		pot+=1
		cont=10**pot
		
	st1 = str(cont)
	ok = True
	for a in range(2,7):
		for b in str(a*cont):
			if(not b in st1):
				ok = False
				break
		
		if(not ok):
			break
	
	if(ok):
		break
	cont+=1

print(cont)