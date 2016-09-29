import math
p = []

def isPrime(n):
	if n <= 1:
		return False
	elif n in p:
		return True
	else:
		i = 2
		while(i <= math.sqrt(n)):
			if(n%i==0):
				return False
			i+=1
		p.append(n)
		return True

def isQP(n):
	if math.sqrt(n)-(math.sqrt(n)//1) == 0:
		return True
	else:
		return False
	
crivo = [0,0]

def Era(n):
	for a in range(2,n+1):
		crivo.append(1)
	
	for a in range(2,n+1):
		for b in range(2*a, n+1, a):
			if(crivo[b]):
				crivo[b]=0
	
	for a in range(n+1):
		if(crivo[a]):
			p.append(a)

a = 9
Era(a)
while(True):
	if(not isPrime(a)):
		i = 0
		norm = False
		while(i<len(p) and p[i] <= a):
			if(isQP((a - p[i])/2)):
				norm = True
			i+=1

		if(not norm):
			print(a)
			break
		
	a+=2