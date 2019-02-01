primes = []
flags = [False, False]

def isPrime(n):
	return flags[n]

def sieve(n):
	for i in range(2, n + 1):
		flags.append(True)
	for i in range(2, int(pow(n, 0.5)) + 1):
		if flags[i]:
			j = i * i
			while j <= n:
				flags[j] = False
				j += i
	for i in range(2, n + 1):
		if flags[i]:
			primes.append(i)

i = 0
n = int(input())
sieve(n)
while n > 3:
	for j in primes:
		if isPrime(n - j):
			n = n - j - j
			i += 1
			break
print(i)
