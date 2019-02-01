from functools import reduce

def primes(x):
    return list(filter(None,map(lambda y:y*reduce(lambda x,y:x*y!=0,map(lambda x,y=y:y%x,range(2,int(pow(y,0.5)+1))),1),range(2,x))))

i = 0
n = int(input())

primeList = primes(n)
flags = []
for j in range(n):
	flags.append(False)
for j in primeList:
	flags[j] = True

def isPrime(x):
	return flags[x]

while n > 3:
	j = 2
	while j < n/2:
		if isPrime(n - j):
			n = n - j - j
			i += 1
			break
		j += 1

print(i)
