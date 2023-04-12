// TITLE: RK Calculator
// DESCRIPTION:
// This program will be able to calculate the R (stadia constant) and K (stadia interval factor)
// from a given data of a transit on a level ground having a horizontal sight and data in metric
// and english units to be used in a topographic survey.

#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void titleDisplay() {

    cout << "-------------------------------------------------------------\n";
    cout << "\t\t\tRK Calculator\n";
    cout << "-------------------------------------------------------------\n";

}

void solveRK(double dataArray[][2], int rows) {

    // R1, R2, R3, ..., Rn -> n is the number of rows - 1 (rows - 1), same goes for K1, K2, K3, ..., Kn

    double R_array[rows - 1];
    double K_array[rows - 1];

    for (int i = 0; i < rows - 1; i++) {    // solves for the Rn values
        
        R_array[i] = ((dataArray[0][0] * dataArray[i + 1][1]) - (dataArray[i + 1][0] * dataArray[0][1])) / (dataArray[i + 1][1] - dataArray[0][1]);

    }

    cout << endl;

    for (int j = 0; j < rows - 1; j++) {

        K_array[j] = (dataArray[j + 1][0] - dataArray[0][0]) / (dataArray[j + 1][1] - dataArray[0][1]);

    }

    double R = 0, K = 0;

    for (int i = 0; i < rows - 1; i++) {    
        R += R_array[i];                    // sums up the R values
        K += K_array[i];                    // sums up the K values
    }

    cout << "The following results were calculated based on data of a \ntransit on a level ground at a horizontal sight:\n";
    cout << "> Stadia Constant (R) = " << setprecision(4) << fixed << R / (rows - 1) << endl;
    cout << "> Stadia Interval Factor (K) = " << setprecision(4) << fixed << K / (rows - 1) << endl;

}

void dataDisplay(double dataArray[][2], int rows) {

    char choice;

    //system("CLS");

    //titleDisplay();
    
    cout << "\n+-----------------------------------------------------------+\n|\t\t\t   DATA SET\t\t\t    |\n";
    cout << "+" << setfill('-') << setw(30) << "+" << setfill('-') << setw(30) << "+";
    cout << "\n|" << setfill(' ') << setw(23) << "Distance Measured" << setw(7);
    cout << "|" << setfill(' ') << setw(20) << "Rod Reading" << setw(10) <<   setfill(' ') << "|";
    cout << "\n+" << setfill('-') << setw(30) << "+" << setfill('-') << setw(31) << "+\n";

    for (int i = 0; i < rows; i++) {
        
        cout << "|" << setw(15) << setfill(' ') << dataArray[i][0] << setw(15) << "|" << setw(17) << dataArray[i][1] << setw(13) << "|";

        cout << endl;
    }

    cout << "+" << setfill('-') << setw(30) << "+" << setfill('-') << setw(31) << "+\n";

}

void dataInquiry(int rows) {

    double dataArray[rows][2] = {0};

    for (int i = 0; i < rows; i++) {    // this for loop accepts user input for the Distances and Rod Readings
        
        //system("CLS");

        //titleDisplay();
                
        cout << endl;

        cout << "Enter value for Distance (d" << i + 1 << "):\t\t";
        cin >> dataArray[i][0];

        cout << "Enter value for Rod Reading (S" << i + 1 << "):\t";
        cin >> dataArray[i][1];
    }

    dataDisplay(dataArray, rows);
    solveRK(dataArray, rows);
    
}

int main() {

    int decision = 1;

    while (decision != 0) {

        system("CLS");

        int rows = 0;  // rows are the number of data to be input, columns are for the Distance and Rod Reading
        
        titleDisplay();

        cout << "Enter the number of Distances/Rod Readings: ";
        cin >> rows;

        dataInquiry(rows);



        cout << "\nDo you want to continue (press any number) or not (press 0): ";
        cin >> decision;
    }

    return 0;
}
