from random import randint
friends = 500000
print("500000")
for i in range(500000):
	print(randint(0,1000000), end=' ')
print("\n" + str(friends) + "1 500000")
for i in range(friends - 1):
	start = randint(1, 500000)
	print(start, end=' ')
	print(randint(start, 500000))
print()