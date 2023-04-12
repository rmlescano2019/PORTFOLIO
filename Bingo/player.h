#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int chooseCard(int playerNum);
void displayCard(int card[5][5]);
int checkCard(int card[5][5], int drawnNumber, int pattern, int playerNum);


#endif