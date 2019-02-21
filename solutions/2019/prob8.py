#coded by someone
linecounts = []
outputs = []
lineNum = 0
while(True):
	line = input()
	if line[0:7] == 'THE END':
		break
	words = line.split()
	linecounts.append("")
	for word in words:
		linecounts[lineNum] += str(len(word))
	if linecounts[lineNum] == '':
		linecounts[lineNum] = '0'
	lineNum += 1
lineNum = 1
total = 0
for line in linecounts:
	outputs.append("Line " + str(lineNum) + " = " + str(line))
	total += int(line)
	lineNum += 1
outputs.append("Sum of file = " + str(total))
for output in outputs:
	print(output)