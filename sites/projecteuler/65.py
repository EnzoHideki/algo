v = []

def gcd(a,b):
	if (b == 0):
		return a
	
	return gcd(b, a%b)

def lcm(a,b):
	return (a//gcd(a,b)) * b

def gen():
	for i in range(1,151):
		if (i % 3 == 2):
			v.append(((i//3)+1)*2)
		else:
			v.append(1)

def build(i):
	if (i == 99):
		return Fraction(0,1)

	return Fraction(1, Fraction(v[i],1) + build(i+1))

class Fraction:
	num = 0
	den = 1

	def __init__(self, a, b):
		if type(b) == int:
			self.num = a
			self.den = b
		else:
			self.num = a * b.den
			self.den = b.num

	def __radd__(self, other):
		common = lcm(self.den, other.den)
		return Fraction((common//self.den)*self.num + (common//other.den)*other.num, common)

	def __add__(self, other):
		common = lcm(self.den, other.den)
		return Fraction((common//self.den)*self.num + (common//other.den)*other.num, common)


def main():
	gen()

	fin = Fraction(2,1) + build(0)

	ans = 0
	for i in str(fin.num):
		ans += ord(i)-ord('0')

	print(ans)

main()