from collections import Counter
import math

n = int(input())
stock = Counter(map(int, input().split()))

subn = math.ceil(n/2)
need = [[4 for col in range(subn)] for row in range(subn)]
use = [[0 for col in range(subn)] for row in range(subn)]

if n == 1:
	print("YES")
	print(stock.most_common(1)[0][0])
	exit()

if n % 2:
	for row in range(subn):
		need[row][subn - 1] = 2
		need[subn - 1][row] = 2
	need[subn - 1][subn - 1] = 1

for row in range(subn):
	for col in range(subn):
		mc = stock.most_common(1)[0]
		if(need[row][col] > mc[1]):
			print("NO")
			exit()
		stock[mc[0]] -= need[row][col]
		use[row][col] = mc[0]

print("YES")

for row in range(subn):
	for col in range(subn):
		print(use[row][col], end=' ')
	for col in reversed(range(1, subn - n%2)):
		print(use[row][col], end=' ')
	print(use[row][0])
for row in reversed(range(1, subn - n%2)):
	for col in range(subn):
		print(use[row][col], end=' ')
	for col in reversed(range(1, subn - n%2)):
		print(use[row][col], end=' ')
	print(use[row][0])
for col in range(subn):
	print(use[0][col], end=' ')
for col in reversed(range(1, subn - n%2)):
	print(use[0][col], end=' ')
print(use[0][0])