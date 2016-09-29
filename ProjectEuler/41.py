import math

primes = []

def isPrime(n):
	if n <= 1:
		return False
	elif n in primes:
		return True
	else:
		i=2
		while(i <= math.sqrt(n)):
			if(n%i==0):
				return False
			i+=1
		return True

fat = [1,1]

def fato(n):
	if(len(fat) <= n):
		for i in range(len(fat), n+1):
			fat.append(i*fat[i-1])
	return fat[n]
	
def mkPan(n):
	u = []
	ret = []
	aux = []
	
	for i in range(0,n):
		aux.append(1)
		
	cont = 0
	
	while(cont < fato(n)):
		for i in range(0,n):
			u.append(i+1)
			aux[i] = ((cont//fato(n-1-i))%(n-i))+1
		aa=0
		for i in range(0,n):
			aa += u[aux[i]-1]*10**(n-1-i)
			u.remove(u[aux[i]-1])
			
		ret.append(aa)
		cont+=1
		
	return ret

for a in range(1,10):
	c = mkPan(a)
	for b in c:
		if isPrime(b):
			print(b)