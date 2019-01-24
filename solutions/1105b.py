import re
from string import ascii_lowercase

k = input().strip().split(' ')[1]
s = input().strip()

maxLevel = 0
for c in ascii_lowercase:
    charLevel = len(re.findall('{0}{{{1}}}'.format(c, k), s))
    maxLevel = max(maxLevel, charLevel)

print(maxLevel)
