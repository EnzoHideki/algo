def gcd(a,b):
	if a == 0:
		return b
	if b == 0:
		return a

	return 1 if (a == 1 or b == 1) else gcd(a, a%b) if a>b else gcd(b, b%a)

def lcm(a,b):
	return (a*b)//gcd(a,b)

def sum(a,b):
	c = [0,0]
	c[1] = lcm(a[1],b[1])
	c[0] = (c[1]*a[0])//a[1] + (c[1]*b[0])//b[1]
	return c

def inverse(f):
	inv = [0,0]
	inv[0] = f[1]
	inv[1] = f[0]
	return inv

one = [1,1]
two = [2,1]

base = [1,2]

ans = 0

for i in range(1000):
	base = inverse(sum(base,two))
	res = sum(base,one)

	if (len(str(res[0])) > len(str(res[1]))):
		ans+=1

print(ans)