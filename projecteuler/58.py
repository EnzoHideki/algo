import math

def isPrime(n):
	if n <= 1:
		return False
	it = 2
	while (it <= math.sqrt(n)):
		if (n % it == 0):
			return False
		it+=1

	return True



def main():
	i = 1
	primes = 0
	diag = 1
	step = 0
	while (True):
		step += 2
		diag += 4
		for j in range(4):
			i += step
			if isPrime(i):
				primes+=1

		if primes < 0.1*diag:
			print(step+1)
			return

main()