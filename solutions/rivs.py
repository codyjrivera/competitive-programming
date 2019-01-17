# UA Gold Team - Team 333 - Div II - Room J-156

vals = str(input()).split(" ")
maxIndex = vals[0]
spotsToRotate = vals[1]
riv1str = str(input()).split(" ")
riv2str = str(input()).split(" ")
riv1 = []
riv2 = []
for i, num in enumerate(riv1str):
    if i != 0:
        riv1.append(int(num))
for i, num in enumerate(riv2str):
    if i != 0:
        riv2.append(int(num))
j = 0
#add 'em
sumRiv = []
productRiv = []
rotatedRiv1 = []
rotatedRiv2 = []

for i in riv1:
    while j < len(riv1) and abs(riv2[j]) < abs(i):
        j = j + 1
    #at same index
    if abs(riv2[j]) == abs(i):
        val1 = i / abs(i)
        val2 = riv2[j] / abs(riv2[j])
        sum = val1 + val2
        product = val1 * val2
        if product != 0:
            productRiv.append(int(abs(i) * product))
i = 0
j = 0
while i < len(riv1):
    while j < len(riv2) and (abs(riv2[j]) < abs(riv1[i])):
        sumRiv.append(riv2[j])
        j = j + 1
    if abs(riv2[j]) == abs(riv1[i]):
        val1 = riv1[i] / abs(riv1[i])
        val2 = riv2[j] / abs(riv2[j])
        sum = val1 + val2
        if sum < -1:
            sum = -1
        if sum > 1:
            sum = 1
        if sum != 0:
            sumRiv.append(abs(riv1[i]) * sum)
        j = j + 1
    else:
        sumRiv.append(riv1[i])
    i = i + 1
while j < len(riv2):
    sumRiv.append(riv2[j])
    j = j + 1

outputSum = str(len(sumRiv))
for item in sumRiv:
    outputSum = outputSum + " " + str(item)
print(outputSum)
outputProduct = str(len(productRiv))
for item in productRiv:
    outputProduct = outputProduct + " " + str(item)
print(outputProduct)

def rivItemKey(item):
    return abs(item)

rotatedRiv1 = []
for value in riv1:
    calcedNum = (abs(value) - int(spotsToRotate)) % int(maxIndex) * (value / abs(value))
    if calcedNum == 0:
        calcedNum = int(maxIndex) * (value / abs(value))
    rotatedRiv1.append(int(calcedNum))
rotatedRiv1.sort(key=rivItemKey)
outputRotatedRiv1 = str(len(rotatedRiv1))
for item in rotatedRiv1:
    outputRotatedRiv1 = outputRotatedRiv1 + " " + str(item)
print(outputRotatedRiv1)

rotatedRiv2 = []
for value in riv2:
    calcedNum = (abs(value) - int(spotsToRotate)) % int(maxIndex) * (value / abs(value))
    if calcedNum == 0:
        calcedNum = int(maxIndex) * (value / abs(value))
    rotatedRiv2.append(int(calcedNum))
rotatedRiv2.sort(key=rivItemKey)
outputRotatedRiv2 = str(len(rotatedRiv2))
for item in rotatedRiv2:
    outputRotatedRiv2 = outputRotatedRiv2 + " " + str(item)
print(outputRotatedRiv2)
