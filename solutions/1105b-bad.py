import re
from string import ascii_lowercase

nk = input().strip().split(' ')
n = int(nk[0])
k = int(nk[1])
s = input().strip()

maxLevel = 0
for c in ascii_lowercase:
	x = n // k # Maximum level based on n and k
	while x > maxLevel and not re.match('({0}{{{1}}}.{{0,{2}}}){{{3}}}'.format(c, k, n // x - k, x), s):
		# Maximum of n // x - k characters after each run of k characters c
		x -= 1
	maxLevel = x

print(maxLevel)
