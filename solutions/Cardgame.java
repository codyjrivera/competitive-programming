import java.util.Scanner;

public class Cardgame {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String tableCard = scanner.nextLine();
		String[] myCards = scanner.nextLine().split(" ");
		for(String card : myCards) {
			if(card.charAt(0) == tableCard.charAt(0) || card.charAt(1) == tableCard.charAt(1)) {
				System.out.println("YES");
				scanner.close();
				System.exit(0);
			}
		}
		System.out.println("NO");
		scanner.close();
		System.exit(0);
	}
}
