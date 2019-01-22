#include <stdio.h>

int main() {
	char tableCard[2];
	scanf("%2s", tableCard);
	char card[2];
	for(int i = 0; i < 5; i++) {
		scanf("%2s", card);
		if(card[0] == tableCard[0] || card[1] == tableCard[1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
