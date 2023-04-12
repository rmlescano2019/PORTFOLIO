#include "player.h"

//------------------------------------------------------------------------------------------------------------------------------- 
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

//------------------------------------------------------------------------------------------------------------------------------- 
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
			printf("%d\t", *(*(card+i) + j)); //use pointers here
		}
		printf("\n");
	}
	printf("\n");
}

//------------------------------------------------------------------------------------------------------------------------------- 
int checkCard(int card[5][5], int drawnNumber, int pattern, int playerNum)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (*(*(card+i) + j) == drawnNumber) //Use pointers here
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

	if (pattern == 1 && card[0][0] + card[0][4] + card[4][0] + card[4][4] == 0)
	{
		return 1;
	}
	if (pattern == 2)
	{
		for (int i = 0; i < 5; i++)
		{
			if (card[i][0] + card[i][1] + card[i][2] + card[i][3] + card[i][4] == 0)
			{
				return 1;
			}
		}
	}
	if (pattern == 3)
	{
		for (int i = 0; i < 5; i++)
		{
			if (card[0][i] + card[1][i] + card[2][i] + card[3][i] + card[4][i] == 0)
			{
				return 1;
			}
		}
	}

	return 0;
}