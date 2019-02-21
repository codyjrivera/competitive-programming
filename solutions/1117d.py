from math import factorial

st = input().split()

n = int(st[0])
m = int(st[1])

sum = 0

for k in range(0, n//m + 1):
	a = n // m - k
	b = n % m + k * m
	prod = 1
	for x in range(a + 1, a + b + 1):
		prod *= x
	prod //= factorial(b)
	sum += prod
	sum %= 1000000007

print(sum)