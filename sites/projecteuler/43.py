fat = [1,1]
def fato(n):
	if n >= len(fat):
		for a in range(len(fat), n+1):
			fat.append(fat[a-1]*a)
	return fat[n]

def mkPan(n):
	pan = []
	
	aux = [2]
	for a in range(n):
		aux.append(1)
		
	cont = 0
	while(cont < n*fato(n)):
		na = []
		for a in range(n+1):
			na.append(a)

		s=0
		for a in range(len(aux)):
			s+=10**(n-a)*na[aux[a]-1]
			na.remove(na[aux[a]-1])
		
		print(s)
		pan.append(s)
		cont+=1
		print(s)
		for a in range(len(aux)):
			aux[a] = ((cont//fat[len(aux)-a-1])%(len(aux)-a))+1
		
		aux[0]+=1
	
	return pan

def isPan(n):
	dig=[]
	while(n>0):
		a = n%10
		if(a in dig):
			return False
		dig.append(a)
		n = n//10
	
	return True

'''p9 = mkPan(9)
s = 0
for a in p9:
	print(a)
	d = []
	
	for b in range(7):
		d.append((a%(10**(3+b)))//10**b)
	
	if(d[0]%17==0 and d[1]%13==0 and d[2]%11==0 and d[3]%7==0 and d[4]%5==0 and d[5]%3==0 and d[6]%2==0):
		s+=a
print(s)'''
s=0
for a in range(1023456789, 9876543211):
	print(a)
	if(isPan(a)):
		print(a)
		d = []

		for b in range(7):
			d.append((a%(10**(3+b)))//10**b)

		if(d[0]%17==0 and d[1]%13==0 and d[2]%11==0 and d[3]%7==0 and d[4]%5==0 and d[5]%3==0 and d[6]%2==0):
			s+=a
print(s)

#16695334890 found non-optimal