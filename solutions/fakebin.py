number = input().strip()
outputs = []
while len(number) == 0:
	number = input().strip()
while number[0] != '-':
	total = 0
	i = 1
	while True:
		fakeBin = int("{0:b}".format(i))
		if fakeBin > int(number):
			break
		total += fakeBin
		i += 1
	outputs.append(total)
	number = input().strip()
	while len(number) == 0:
		number = input().strip()
for output in outputs:
	print(output)