#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void generateCards(int cards[5][5][5]);
void generateNumbers(int[5], int, int);
int checkDup(int numbersHolder[], int num, int cntr, int limit);
int randomizePattern();
void replicateCard(int originalCard[5][5], int replica[5][5]);
int drawNumber(int [75], int);

#endif