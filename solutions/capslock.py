import re
word = input().strip()
if re.match('^[a-z]?[A-Z]*$', word) is not None:
	word = word.swapcase()
print(word)
