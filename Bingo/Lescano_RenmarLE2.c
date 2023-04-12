#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

//---------------------------------------------------------------------------- PART 1
void generateCards(int cards[5][5][5]);
void generateNumbers(int letterNums[5], int lowlimit, int uplimit);
int checkDup(int numbersHolder[], int num, int cntr, int limit);
//---------------------------------------------------------------------------- PART 1
//
//---------------------------------------------------------------------------- PART 2
int chooseCard(int playerNum);
void replicateCard(int originalCard[5][5], int replica[5][5]);
void displayCard(int card[5][5]);
//---------------------------------------------------------------------------- PART 2
//
//---------------------------------------------------------------------------- PART 3
int randomizePattern();
int drawNumber(int drawnNumbers[75], int cntr);
int checkCard(int card[5][5], int drawnNumber, int pattern, int playerNum);

//---------------------------------------------------------------------------- PART 3


//--------------------------------------------------------------------------------------------------------------------------------------------------- MAIN
int main(){
//--------------------------------------------------------------------------------------------------------------------------- START PART 1
	
	int cards[5][5][5], player1Card[5][5], player2Card[5][5], drawnNumbers[75];
	int column = 0, drawnNumber = 0;
	char letter;

	srand(time(0));

	generateCards(cards);	// from system.c		CHANGES: cards

//--------------------------------------------------------------------------------------------------------------------------- END PART 1
//
//
//
//
//--------------------------------------------------------------------------------------------------------------------------- START PART 2

	int player1Choice = chooseCard(1);	// from player.c
	system("cls");
	printf("Player 1 has chosen the card no. %d\n", player1Choice);
	printf("Displaying card chosen by player 1.\n");
	replicateCard(cards[player1Choice-1], player1Card);	// from system.c	CHANGES: cards[player1Choice-1]
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
	replicateCard(cards[player2Choice-1], player2Card);	// from system.c	CHANGES: cards[player2Choice-1]
	displayCard(player2Card);	// from player.c

	printf("Press ENTER to continue.\n");
	getch();
	system("cls");

//--------------------------------------------------------------------------------------------------------------------------- END PART 2
//
//
//
//
//--------------------------------------------------------------------------------------------------------------------------- START PART 3
	
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

//--------------------------------------------------------------------------------------------------------------------------- END PART 3



}
//--------------------------------------------------------------------------------------------------------------------------- START PART 1
void generateCards(int cards[5][5][5])	// CHANGES: cards[5][5][5]
{
	int randomizedB[5], randomizedI[5], randomizedN[5], randomizedG[5], randomizedO[5];

	int lowLimB = 1, upLimB = 15;
	int lowLimI = 16, upLimI = 30;
	int lowLimN = 31, upLimN = 45;
	int lowLimG = 46, upLimG = 60;
	int lowLimO = 61, upLimO = 75;

	for (int cardNum = 0; cardNum < 5; cardNum++)	// Card Number
	{
		generateNumbers(randomizedB, lowLimB, upLimB);	// case 0 from the 3rd for-loop
		generateNumbers(randomizedI, lowLimI, upLimI);
		generateNumbers(randomizedN, lowLimN, upLimN);
		generateNumbers(randomizedG, lowLimG, upLimG);
		generateNumbers(randomizedO, lowLimO, upLimO);

		printf("Card No. %d\n", cardNum+1);
		printf("\tB\tI\tN\tG\tO\n");
		for (int cardRow = 0; cardRow < 5; cardRow++)	// Rows
		{
			switch (cardRow)
			{
				case 0: printf("B\t"); break;
				case 1: printf("I\t"); break;
				case 2: printf("N\t"); break;
				case 3: printf("G\t"); break;
				case 4: printf("O\t"); break;
			}

			for (int cardCol = 0; cardCol < 5; cardCol++)	// Columns
			{
				switch (cardCol)		// CHANGES: cards[cardNum][cardRow][cardCol] = randomizedB[cardRow]; and so on
				{
					case 0: cards[cardNum][cardRow][cardCol] = randomizedB[cardRow];			// along column B
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 1: cards[cardNum][cardRow][cardCol] = randomizedI[cardRow];			// along column I
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 2: cards[cardNum][cardRow][cardCol] = randomizedN[cardRow];			// along column N
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 3: cards[cardNum][cardRow][cardCol] = randomizedG[cardRow];			// along column G
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 4: cards[cardNum][cardRow][cardCol] = randomizedO[cardRow];			// along column O
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
				}
			}
			printf("\n");
		}
		printf("\n");
	}

}

void generateNumbers(int letterNums[5], int lowlimit, int uplimit)
{
	int numbersHolder[5];

	int randomNum = 0, cntr = 0;	// cntr = counter
	
	while (cntr < 5)
	{
		randomNum = (rand() % (uplimit - lowlimit + 1)) + lowlimit;
		if (checkDup(numbersHolder, randomNum, cntr, 5) == 0)
		{
			letterNums[cntr] = randomNum;	// CHANGES: letterNums[cntr] = randomNum;
			cntr++;
		}
		else
			continue;
	}
}

int checkDup(int numbersHolder[], int num, int cntr, int limit)		// CHANGES: int numbersHolder[5]
{
	for (int i = 0; i < limit; i++)
	{
		if (numbersHolder[cntr-i] == num)	// CHANGES: numbersHolder[cntr-i] == num
		{
			return 1;
		}
	}

	numbersHolder[cntr] = num;
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------- END PART 1
//
//
//
//
//--------------------------------------------------------------------------------------------------------------------------- START PART 2
int chooseCard(int playerNum)
{
	int choice = 0;

	while (1)
	{
		printf("Player %d pick a card: ", playerNum);
		scanf("%d", &choice);

		if (choice < 1 || choice > 5)
		{
			printf("Please choose among the five cards only. Try again.\n");
		}
		else
		{
			break;
		}
	}

	return choice;
}

void replicateCard(int originalCard[5][5], int replica[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			replica[i][j] = originalCard[i][j];		// CHANGES: replica[i][j] = originalCard[i][j]
		}
	}
}

void displayCard(int card[5][5])
{
	printf("\n");
	printf("\tB\tI\tN\tG\tO\n");
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0: printf("B\t"); break;
			case 1: printf("I\t"); break;
			case 2: printf("N\t"); break;
			case 3: printf("G\t"); break;
			case 4: printf("O\t"); break;
		}

		for (int j = 0;  j < 5; j++)
		{
			printf("%d\t", *(*(card+i) + j)); //use pointers here		CHANGES: *(*(card+i) + j)
		}
		printf("\n");
	}
	printf("\n");
}

//--------------------------------------------------------------------------------------------------------------------------- END PART 2
//
//
//
//
//--------------------------------------------------------------------------------------------------------------------------- START PART 3
int randomizePattern()
{
	int lowlimit = 1, uplimit = 3;

	printf("Patterns available in the system:\n");
	printf("1.\tFour Corners\n2.\tStraight Line Across\n3.\tStraight Line Down\n\n");
	printf("Randomizing pattern...\n");

	int randomNum = (rand() % (uplimit - lowlimit + 1)) + lowlimit;

	printf("Pattern randomized is: %d\n", randomNum);

	return randomNum;
}

int drawNumber(int drawnNumbers[75], int cntr)
{
	int lowlimit = 1, uplimit = 75;

	int randomNum = 0;

	while (1)
	{
		randomNum = (rand() % (uplimit - lowlimit + 1)) + lowlimit;
		if (checkDup(drawnNumbers, randomNum, cntr, cntr+1) == 0)	// checkDup(drawnNumbers, randomNum, cntr, cntr+1)
		{
			drawnNumbers[cntr] = randomNum;		// CHANGES: drawnNumbers[cntr] = randomNum;
			break;
		}
		else
		{
			continue;
		}
	}

	return randomNum;
}

int checkCard(int card[5][5], int drawnNumber, int pattern, int playerNum)	// checkCard(player1Card, drawnNumber, pattern, 1)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (*(*(card+i) + j) == drawnNumber) //Use pointers here		CHANGES: *(*(card+i) + j) == drawnNumber
			{
				printf("\n\nMarking matching number with 0.\n");
				card[i][j] = 0;
			}
		}
	}

	printf("\nPress ENTER to check player %d card.\n", playerNum);
	getch();

	displayCard(card);

	printf("Press ENTER to continue.\n");
	getch();
	system("cls");

	if (pattern == 1 && card[0][0] + card[0][4] + card[4][0] + card[4][4] == 0)	// CHANGES HERE
	{
		return 1;
	}
	if (pattern == 2)				// Horizontal Line
	{
		for (int i = 0; i < 5; i++)
		{
			if (card[i][0] + card[i][1] + card[i][2] + card[i][3] + card[i][4] == 0)	// CHANGES HERE
			{
				return 1;
			}
		}
	}
	if (pattern == 3)				// Vertical Line
	{
		for (int i = 0; i < 5; i++)
		{
			if (card[0][i] + card[1][i] + card[2][i] + card[3][i] + card[4][i] == 0)	// CHANGES HERE
			{
				return 1;
			}
		}
	}

	return 0;
}




//--------------------------------------------------------------------------------------------------------------------------- END PART 3
