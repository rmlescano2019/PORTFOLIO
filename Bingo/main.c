#include "main.h"

//------------------------------------------------------------------------------------------------------------------------------- CHECKED
int main()
{
	int cont = 1;
	while (cont)
	{
		system("cls");
		printf("Let's play BINGO!\n\nThis game is not a gambling game because no bets are required from the players.\n");
	
		printf("\nPress ENTER to continue...");
		getch();

		system("cls");

		startGame();

		printf("Would you like to play again?\nPress any number to continue, 0 to stop: ");
		scanf("%d", &cont);
	}

	printf("Closing game. See you next time!\n");

	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------- 
void startGame()
{
// PART 1 STARTS HERE
	int cards[5][5][5], player1Card[5][5], player2Card[5][5], drawnNumbers[75];
	int column = 0, drawnNumber = 0;
	char letter;

	srand(time(0));

	generateCards(cards);	// from system.c
// PART2 STARTS HERE
	int player1Choice = chooseCard(1);	// from player.c
	system("cls");
	printf("Player 1 has chosen the card no. %d\n", player1Choice);
	printf("Displaying card chosen by player 1.\n");
	replicateCard(cards[player1Choice-1], player1Card);	// from system.c
	displayCard(player1Card);	// from player.c

	printf("Press ENTER to continue to the other player.\n");
	getch();
	system("cls");

	int player2Choice = chooseCard(2);	// from player.c
	while (player2Choice == player1Choice)
	{
		printf("Player 1 has already chosen this card. Pick again.\n");
		player2Choice = chooseCard(2);	// from player.c
	}
	printf("Player 2 has chosen the card no. %d\n", player2Choice);
	printf("Displaying card chosen by player 2.\n");
	replicateCard(cards[player2Choice-1], player2Card);	// from system.c
	displayCard(player2Card);	// from player.c

	printf("Press ENTER to continue.\n");
	getch();
	system("cls");
// PART3 STARTS HERE
	int pattern = randomizePattern();	// from system.c

	printf("\nDrawing numbers now...\n\n");
	for (int cntr = 0; cntr < 75; cntr++)
	{
		drawnNumber = drawNumber(drawnNumbers, cntr);	// from system.c

		if (drawnNumber >= 1 && drawnNumber <= 15)
			letter = 'B';
		else if (drawnNumber >= 16 && drawnNumber <= 30)
			letter = 'I';
		else if (drawnNumber >= 31 && drawnNumber <= 45)
			letter = 'N';
		else if (drawnNumber >= 46 && drawnNumber <= 60)
			letter = 'G';
		else
			letter = 'O';

		printf("%d in the line of %c\n", drawnNumber, letter);

		if (checkCard(player1Card, drawnNumber, pattern, 1))	// from player.c
		{
			printf("BINGO!\nPlayer 1 completed the required pattern. Congratulations!\n");
			break;
		}
		if (checkCard(player2Card, drawnNumber, pattern, 2))	// from player.c
		{
			printf("BINGO!\nPlayer 2 completed the required pattern. Congratulations!\n");
			break;
		}
		if (cntr == 75)
		{
			printf("It's a tie! Game over.\n");
		}
	}
}