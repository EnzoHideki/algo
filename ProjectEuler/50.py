import math

p = []
	
crivo = [0,0]

def Era(n):
	for i in range(2,n+1):
		crivo.append(1)
		
	for a in range(2,n+1):
		for b in range(2*a, n+1, a):
			if crivo[b]:
				crivo[b]=0;
	
def main():
	Era(1000000)
	ans = 0
	
	for a in range(1000001):
		if(crivo[a]):
			p.append(a)
	maxp = p[len(p)-1]
	so=0
	for i in range(21):
		so+=p[i]
			
	for a in range(21,1000000):
		print(a)
		b = a
		so += p[a]
		s = so
		if(s >= 1000000):
			break
		while(b < len(p)-1):
			if(s >= 1000000):
				break
			if(s in p):
				ans = s
			
			s = s-p[b-a]+p[b+1]
			b+=1
		
	print("final:",ans)
	
main()