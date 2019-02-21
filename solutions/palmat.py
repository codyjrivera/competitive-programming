from collections import Counter
import math
import sys

n = int(input())
stock = Counter(map(int, input().split()))

subn = math.floor(n/2)
use = [[0 for col in range(subn)] for row in range(subn)]

if n == 1:
	print("YES")
	print(stock.most_common(1)[0][0])
	exit()

for row in range(subn):
	for col in range(subn):
		mc = stock.most_common(1)[0]
		if(mc[1] < 4):
			print("NO")
			exit()
		stock[mc[0]] -= 4
		use[row][col] = mc[0]

if n % 2:
	for row in range(subn):
		mc = stock.most_common(1)[0]
		if(mc[1] < 2):
			print("NO")
			exit()
		stock[mc[0]] -= 2
		use[row].append(mc[0])
	use.append([])
	for col in range(subn):
		mc = stock.most_common(1)[0]
		if(mc[1] < 2):
			print("NO")
			exit()
		stock[mc[0]] -= 2
		use[subn].append(mc[0])
	mc = stock.most_common(1)[0]
	if(mc[1] < 1):
		print("NO")
		exit()
	use[subn].append(mc[0])
	subn += 1 # for printing

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