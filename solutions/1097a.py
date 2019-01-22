tableCard = input()
cards = input().split(' ')
for card in cards:
	if card[0] == tableCard[0] or card[1] == tableCard[1]:
		print("YES")
		exit()
print("NO")
