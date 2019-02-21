number = input().strip()
outputs = []
while len(number) == 0:
	number = input().strip()
while number[0] != '-':
	lastFake = ''
	for digit in number:
		if digit == '0':
			lastFake += '0'
		else:
			lastFake += '1'
	total = 0
	for i in range(1, int(lastFake, 2) + 1):
		binRep = "{0:b}".format(i)
		total += int(binRep)
	outputs.append(total)
	number = input().strip()
	while len(number) == 0:
		number = input().strip()
for output in outputs:
	print(output)