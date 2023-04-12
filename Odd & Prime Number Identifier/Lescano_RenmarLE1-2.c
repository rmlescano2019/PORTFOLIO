#include <stdio.h>
#include <string.h>
#include <math.h>

//------------------------------------------------------------------------------------------------- FUNCTION DECLARATIONS
int checkPerfectNum(int);

int generatePrimeComposite(int);
int checkPrimeComposite(int, int);

int generateOdd(int);
int generateEven(int);

//------------------------------------------------------------------------------------------------- MAIN
int main(){

    int userInput, count = 2, decision = 0;

    printf("\n\t\t>>> FIRST LONG CODING EXAM <<<\n");

    while (decision != 1)
    {
        printf("\n---------------------------------------------------------------\nPlease enter a number: ");
        scanf("%d", &userInput);

        if (userInput == 1)
        {
            printf("---------------------------------------------------------------\nThe number \'%d\' has the following characteristics:\n", userInput);
            printf("\nODD NUMBER\n>> There are no previous Prime numbers to display.");
        }
        else if (userInput < 1)
        {
            printf("\n>>> INVALID INPUT. PLEASE ENTER A POSITIVE INTEGER. <<<\n");
            continue;
        }
        else
        {
            printf("---------------------------------------------------------------\nThe number \'%d\' has the following characteristics:\n", userInput);

            checkPerfectNum(userInput);

            generatePrimeComposite(userInput);

            if (checkPrimeComposite(userInput, count) == 0)
            {
                printf("\n\nPRIME NUMBER\n>> The 5 previous Odd number/s before %d is/are:", userInput);
                generateOdd(userInput);
            }
            else
            {
                printf("\n\nCOMPOSITE NUMBER\n>> The next 5 Even numbers after %d are:", userInput);
                generateEven(userInput);
            }

        }

        printf("\n---------------------------------------------------------------\n\nDo you want to continue (press any number) or not (press 1)? ");
        scanf("%d", &decision);
    }
    
    printf("\n---------------------------------------------------------------\n\t\t\t   Thank you!\n---------------------------------------------------------------\n");
}

//------------------------------------------------------------------------------------------------- PERFECT NUMBER
int checkPerfectNum(int userInput)
{
    int ans = 0, num = 1, getRoot;

    while (num < userInput)
    {
        if (userInput%num == 0)
        {
            ans += num;
            ++num;
        }
        else
        {
            ++num;
        }
    }

    if (ans == userInput)           // Perfect Number
    {
        printf("\nPERFECT NUMBER\n");   // TRUE
        
        printf(">> Do you want to get its root (press 1) or not (press any number)? ");
        scanf("%d", &getRoot);

        if (getRoot == 1)
        {
            printf(">> Root value: %f\n", sqrt(userInput));
        }
    }
}

//------------------------------------------------------------------------------------------------- GENERATING THE NEXT/PREVIOUS 5 COMPOSITE/PRIME NUMBERS
int generatePrimeComposite(int userInput)
{
    int iter = 2;

    if (userInput%2 == 1)       // checks for ODD number
    {
        printf("\nODD NUMBER\n>> The 5 previous Prime number/s before %d is/are:", userInput);

        userInput -= 1;
    
        for (int elements = 0; elements < 5; --userInput)   // PRIME NUMBER GENERATOR
        {
            if (userInput < 2)
            {
                break;
            }
            else if (checkPrimeComposite(userInput, iter) == 0)
            {
                printf("  %d", userInput);
                ++elements;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
    else if (userInput%2 == 0)  // checks for EVEN number
    {
        printf("\nEVEN NUMBER\n>> The next 5 Composite numbers after %d are:", userInput);

        userInput += 1;
    
        for (int elements = 0; elements < 5; ++userInput)   // COMPOSITE NUMBER GENERATOR
        {
            if (checkPrimeComposite(userInput, iter) != 0)
            {
                printf("  %d", userInput);
                ++elements;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
}

//------------------------------------------------------------------------------------------------- PRIME OR COMPOSITE CHECKER (RECURSION)
int checkPrimeComposite(int n, int x)
{
    if (n == x)
    {
        return 0;
    }
    else if (n%x != 0)      // PRIME
    {
        return checkPrimeComposite(n, x + 1) + 0;   // returns 0
    }
    else if (n%x == 0)      // COMPOSITE
    {
        return checkPrimeComposite(n, x + 1) + 1;   // returns any number
    }
}

//------------------------------------------------------------------------------------------------- FOR PRIME: GENERATING THE 5 PREVIOUS ODD NUMBERS (ITERATION)
int generateOdd(int userInput)
{
    if (userInput == 2)
    {
        printf("  1");
    }
    else
    {
        userInput -= 10;

        for (int i = 0; i <= 8; ++i)
        {
            if (i%2 == 1)       // check ODD index
            {
                continue;
            }
            else
            {
                if (userInput + i < 1)
                {
                    continue;
                }
                else
                {
                    printf("  %d", userInput + i);
                }
            }
        }
    }
}

//------------------------------------------------------------------------------------------------- FOR COMPOSITE: GENERATING THE NEXT 5 EVEN NUMBERS (ITERATION)
int generateEven(int userInput)
{
    if (userInput%2 == 1)       // ODD Composite
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (i%2 == 1)
            {
                printf("  %d", userInput + i);
            }
            else
            {
                continue;
            }
        }
    }
    else if (userInput%2 == 0)  // EVEN Composite
    {
        for (int i = 2; i <= 10; ++i)
        {
            if (i%2 == 1)
            {
                continue;
            }
            else
            {
                printf("  %d", userInput + i);
            }
        }
    }
}
