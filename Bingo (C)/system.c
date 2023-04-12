#include "system.h"

//------------------------------------------------------------------------------------------------------------------------------- 
void generateCards(int cards[5][5][5])
{
	int randomizedB[5], randomizedI[5], randomizedN[5], randomizedG[5], randomizedO[5];

	int lowLimB = 1, upLimB = 15;
	int lowLimI = 16, upLimI = 30;
	int lowLimN = 31, upLimN = 45;
	int lowLimG = 46, upLimG = 60;
	int lowLimO = 61, upLimO = 75;

	for (int cardNum = 0; cardNum < 5; cardNum++)
	{
		generateNumbers(randomizedB, lowLimB, upLimB);
		generateNumbers(randomizedI, lowLimI, upLimI);
		generateNumbers(randomizedN, lowLimN, upLimN);
		generateNumbers(randomizedG, lowLimG, upLimG);
		generateNumbers(randomizedO, lowLimO, upLimO);

		printf("Card No. %d\n", cardNum+1);
		printf("\tB\tI\tN\tG\tO\n");
		for (int cardRow = 0; cardRow < 5; cardRow++)
		{
			switch (cardRow)
			{
				case 0: printf("B\t"); break;
				case 1: printf("I\t"); break;
				case 2: printf("N\t"); break;
				case 3: printf("G\t"); break;
				case 4: printf("O\t"); break;
			}

			for (int cardCol = 0; cardCol < 5; cardCol++)
			{
				switch (cardCol)
				{
					case 0: cards[cardNum][cardRow][cardCol] = randomizedB[cardRow];
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 1: cards[cardNum][cardRow][cardCol] = randomizedI[cardRow];
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 2: cards[cardNum][cardRow][cardCol] = randomizedN[cardRow];
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 3: cards[cardNum][cardRow][cardCol] = randomizedG[cardRow];
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
					case 4: cards[cardNum][cardRow][cardCol] = randomizedO[cardRow];
							printf("%d\t", cards[cardNum][cardRow][cardCol]);
							break;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}

//------------------------------------------------------------------------------------------------------------------------------- 
void generateNumbers(int letterNums[5], int lowlimit, int uplimit)
{
	int numbersHolder[5];

	int randomNum = 0, cntr = 0;	// cntr = counter
	
	while (cntr < 5)
	{
		randomNum = (rand() % (uplimit - lowlimit + 1)) + lowlimit;
		if (checkDup(numbersHolder, randomNum, cntr, 5) == 0)
		{
			letterNums[cntr] = randomNum;
			cntr++;
		}
		else
			continue;
	}
}

//------------------------------------------------------------------------------------------------------------------------------- 
int checkDup(int numbersHolder[], int num, int cntr, int limit)		// EX: num = 6;	cntr = 0;
{
	for (int i = 0; i < limit; i++)
	{
		if (numbersHolder[cntr-i] == num)
		{
			return 1;
		}
	}

	numbersHolder[cntr] = num;
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------- 
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

//------------------------------------------------------------------------------------------------------------------------------- 
void replicateCard(int originalCard[5][5], int replica[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			replica[i][j] = originalCard[i][j];
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------- 
int drawNumber(int drawnNumbers[75], int cntr)
{
	int lowlimit = 1, uplimit = 75;

	int randomNum = 0;

	while (1)
	{
		randomNum = (rand() % (uplimit - lowlimit + 1)) + lowlimit;
		if (checkDup(drawnNumbers, randomNum, cntr, cntr+1) == 0)
		{
			drawnNumbers[cntr] = randomNum;
			break;
		}
		else
		{
			continue;
		}
	}

	return randomNum;
}