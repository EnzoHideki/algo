l = []

def sumASCII():
	ret = 0
	with open("out", "r") as file:
		for line in file:
			for letter in line:
				ret += ord(letter)

	return ret

def taskOne():
	with open("cipher.txt","r") as file:
		for line in file:
			l = line.split(',')

	for a in range(ord('a'), ord('z')):
		for b in range(ord('a'), ord('z')):
			for c in range(ord('a'), ord('z')):
				key = [chr(a),chr(b),chr(c)]

				i = 0
				sz = len(l)
				s = ""

				while (i < sz):
					s += chr(int(l[i]) ^ ord(key[i%3]))
					i += 1

				print(s)

#taskOne()
print(sumASCII())