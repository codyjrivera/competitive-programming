q = int(input())
for i in range(q):
	nab = [int(i) for i in input().split()]
	n = nab[0]
	a = nab[1]
	b = nab[2]
	if b > 2 * a:
		print(a * n)
	else:
		print(b * (n//2) + a * (n%2))
	