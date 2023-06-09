#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100

// TO DO:
// 1. Finish Round Robin Scheduling
// 2. Fix SJF Scheduling
// 3. Add Idle Times in SJF
// 4. Do Priority Based Scheduling
// 5. Add Idle Times in Priority Based

//---------------------------------------------------------------------------------------------------------------------------------------------- FUNCTION DECLARATIONS
typedef struct {
    int processNum, arrivalTime, burstTime, remainingTime, idleTime, processDone;
} Values;

typedef struct {        // stores the history of processes
    int pNum, pBurst, totalBurst;
} Gantt;

void FCFS(int processes);
void SJF(int processes);
void priorityBased(int processes);
void roundRobin(int processes);

int totalTime(Values value[MAX_COUNT], int processes);
void bubbleSort(Values value[MAX_COUNT], int processes);
int results(Values value[MAX_COUNT], int processes);

// ---------------------------------------------------------------------------------------------------------------------------------------------- MAIN
int main() {

    system("clear");

    int decision, processes;

    while(decision != 5) {

        decision = 0;

        printf("\n\t---- SCHEDULING ALGORITHMS ----\n");
        printf("\t1. FCFS\n\t2. SJF\n\t3. Priority Based\n\t4. Round Robin\n\t5. Exit\n\n\tEnter your choice: ");
        scanf("%d", &decision);

        // Error Handler
        if (decision < 1 || decision > 5) {      
            printf("\n+----------------------------------------------------+\
            \n| WARNING: Please choose a number among the choices. |\
            \n+----------------------------------------------------+\n");
            continue;
        }

        switch (decision) {
            case 1:
                system("clear");

                printf("\n\t>> FCFS Scheduling <<\n\tSpecify the number of processes: ");
                scanf("%d", &processes);

                FCFS(processes);
                decision = 5;
                break;

            case 2:
                system("clear");

                printf("\n\t>> SJF Scheduling <<\n\tSpecify the number of processes: ");
                scanf("%d", &processes);

                SJF(processes);
                decision = 5;
                break;

            case 3:
                system("clear");

                printf("\n\t>> Priority Based Scheduling <<\n\tSpecify the number of processes: ");
                scanf("%d", &processes);

                priorityBased(processes);
                decision = 5;
                break;

            case 4:
                system("clear");

                printf("\n\t>> Round Robin  Scheduling <<\n\tSpecify the number of processes: ");
                scanf("%d", &processes);

                roundRobin(processes);
                decision = 5;
                break;

            case 5:
                break;
        }

    }

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------- SCHEDULING ALGORITHMS
void FCFS(int processes) {      // OK

    Values value[MAX_COUNT];    // created an array "value" of type "struct values" with a capacity of 10

    // SAMPLE DATA
    value[0].processNum = 1, value[0].arrivalTime = 0, value[0].burstTime = 26;
    value[1].processNum = 2, value[1].arrivalTime = 25, value[1].burstTime = 154;
    value[2].processNum = 3, value[2].arrivalTime = 75, value[2].burstTime = 127;
    value[3].processNum = 4, value[3].arrivalTime = 200, value[3].burstTime = 300;
    // SAMPLE DATA

    printf("\n\tEnter the Arrival Time and Burst Time for every process.\n\tFORMAT: Process #: [Arrival Time] [Burst Time]\n\n");
    for (int i = 0; i < processes; i++) {
        printf("\tProcess %d: %d %d\n", i + 1, value[i].arrivalTime, value[i].burstTime);
    }

    results(value, processes);  // process results

}

void SJF(int processes) {

    Values value[MAX_COUNT];    // created an array "value" of type "struct values" with a capacity of 10

    // SAMPLE DATA // SORTED ORDER: P4 P1 P3 P2
    value[0].processNum = 1, value[0].arrivalTime = 0, value[0].burstTime = 26;
    value[1].processNum = 2, value[1].arrivalTime = 25, value[1].burstTime = 154;
    value[2].processNum = 3, value[2].arrivalTime = 75, value[2].burstTime = 127;
    value[3].processNum = 4, value[3].arrivalTime = 200, value[3].burstTime = 300;
    // SAMPLE DATA // SORTED ORDER: P4 P1 P3 P2

    printf("\n\tEnter the Arrival Time and Burst Time for every process.\n\tFORMAT: Process #: [Arrival Time] [Burst Time]\n\n");
    for (int i = 0; i < processes; i++) {
        printf("\tProcess %d: %d %d\n", i + 1, value[i].arrivalTime, value[i].burstTime);
    }

    printf("\nOriginal Array:");
    for (int i = 0; i < processes; i++) {
        printf("\nP%d: %d", value[i].processNum, value[i].burstTime);
    }

    bubbleSort(value, processes);
    printf("\n\nSorted Array:");
    for (int i = 0; i < processes; i++) {
        printf("\nP%d: %d", value[i].processNum, value[i].burstTime);
    }

    results(value, processes);

}

void priorityBased(int processes) {

    printf("\n\t%d\n", processes);

}

void roundRobin(int processes) {

    Values value[MAX_COUNT];    // created an array "value" of type "struct values" with a capacity of 100
    Gantt chart[MAX_COUNT];
    
    int quantum = 20;  // Time Quantum

    // SAMPLE DATA
    value[0].processNum = 1, value[0].arrivalTime = 0, value[0].burstTime = 53, value[0].idleTime = 0;
    value[1].processNum = 2, value[1].arrivalTime = 0, value[1].burstTime = 8, value[1].idleTime = 0;
    value[2].processNum = 3, value[2].arrivalTime = 0, value[2].burstTime = 68, value[2].idleTime = 0;
    value[3].processNum = 4, value[3].arrivalTime = 0, value[3].burstTime = 24, value[3].idleTime = 0;
    // SAMPLE DATA

    printf("\n\tEnter the Arrival Time and Burst Time for every process.\n\tFORMAT: Process #: [Arrival Time] [Burst Time]\n\n");
    for (int i = 0; i < processes; i++) {
        printf("\tProcess %d: %d %d\n", i + 1, value[i].arrivalTime, value[i].burstTime);
        value[i].remainingTime = value[i].burstTime;        // sets the remaining time values the same as the burst time
    }

    printf("\n\tEnter the Time Quantum: %d", quantum);

    // start with P1, minus 20 sa burst time, then add 20 to the idle time of P2, P3, and P4
    // if below time quantum ang remaining time sang isa ka process, then other processes += value[i].burstTime para ma add ang idle time sang other processes
    // then we set, value[i].burstTime = 0

    /* typedef struct {
        int processNum, arrivalTime, burstTime, remainingTime, idleTime, processDone;
    } Values; */

    /* typedef struct {        // stores the history of processes
        int pNum, pBurst, totalBurst;
    } Gantt; */










    int tempBurst = 0, totalBurst = 0, toPrint = 0;          // here, amu ni gamiton nga burst time sa pag add sang idle time sang other processess if in case the burst time of a process is now less than the time quantum

    printf("\n\nGANTT CHART\n");
    //printf("Current i = -\t\tP1 = %d\t\tP2 = %d\t\tP3 = %d\t\tP4 = %d\t\tTotal Time = %d\n", value[0].burstTime, value[1].burstTime, value[2].burstTime, value[3].burstTime, totalTime(value, processes));
    for (int i = 0; i < processes; i++) {

        if (value[i].burstTime == 0) {          // here, if the burst time of the current process is now zero - skip the process
            toPrint = 1;
        }
        else if (value[i].burstTime < quantum) {
            tempBurst = value[i].burstTime;     // here, we store the burst time of the current process - nga less than the time quantum na - to a temporary variable
            totalBurst += tempBurst;            // here, i=add ang current burst time sa total burst sang whole thing
            value[i].burstTime = 0;             // then i-set na ang burst time of the current process to zero
        }
        else {
            totalBurst += quantum;              // here, i-add lang sa total burst time ang quantum
            value[i].burstTime -= quantum;      // then minusan lang ang burst time sang current process sang time quantum
        }

        // LAST PROGRESS IS FIXING THE IDLE TIME OF THE PROCESSES
        // adding the idle time happens here
        for (int j = 0; j < processes; j++) {
            if (j == i || value[j].burstTime == 0) {        // here, we skip the current process in the loop kay ang i-addan lang idle time is ang other processes
                continue;
            }
            else if (value[i].burstTime < quantum) {        // here, is if ang remaining burst time sang current process is below the quantum, so amuna ang i-add nga idle time to other processess
                value[j].idleTime += tempBurst;
            }
            else {
                value[j].idleTime += quantum;               // here, we simply add the idle time of other processess by the given quantum
            }
        }

        // check data
        if (toPrint == 0) {
            //printf("P%d\t", value[i].processNum);     // FINAL PROCESS NUMBER DISPLAY
            //printf("%d\t", totalBurst);               // FINAL BURST DISPLAY
            
            printf("Current i = %d\t\tP1 = %d\t\tP2 = %d\t\tP3 = %d\t\tP4 = %d\t\tTotal Time = %d\nIdle Times:\t\tP1 = %d\t\tP2 = %d\t\tP3 = %d\t\tP4 = %d\n\n",\
            i + 1, value[0].burstTime, value[1].burstTime, value[2].burstTime, value[3].burstTime, totalTime(value, processes), value[0].idleTime, value[1].idleTime, value[2].idleTime, value[3].idleTime);
        }
        else {
            toPrint = 0;
        }





        if (totalTime(value, processes) == 0) {
            printf("\nDONE");
            break;
        }
        else if (i == 3) {
            i -= processes;
        }


        // sa end, if the total remaining time is not yet zero, then i-set ta liwat ang i to zero
        /* if (i == 3) {

            if (totalTime(value, processes) == 0) {
                printf("\ndone");
                break;
            }
            i -= processes;
        } */

    }
    printf("\n\n");

    printf("Idle Time:\t\tP1 = %d\t\tP2 = %d\t\tP3 = %d\t\tP4 = %d", value[0].idleTime, value[1].idleTime, value[2].idleTime, value[3].idleTime);




}
    
// GANTT CHART
// P0       chartIndex = 0      burst = 0                   P1 = 53     P2 = 8      P3 = 68     P4 = 24         TOTAL: 0
// P1       chartIndex = 1      burst = 20                  P1 = 33     P2 = 8      P3 = 68     P4 = 24         TOTAL: 20
// P2       chartIndex = 2      burst = 8                   P1 = 33     P2 = 0      P3 = 68     P4 = 24         TOTAL: 28
// P3       chartIndex = 3      burst = 20                  P1 = 33     P2 = 0      P3 = 48     P4 = 24         TOTAL: 48
// P4       chartIndex = 4      burst = 20                  P1 = 33     P2 = 0      P3 = 48     P4 = 4          TOTAL: 68
// P1       chartIndex = 5      burst = 20                  P1 = 13     P2 = 0      P3 = 48     P4 = 4          TOTAL: 88
// SKIP P2
// P3       chartIndex = 6      burst = 20                  P1 = 13     P2 = 0      P3 = 28     P4 = 4          TOTAL: 108
// P4       chartIndex = 7      burst = 4                   P1 = 13     P2 = 0      P3 = 28     P4 = 0          TOTAL: 112
// P1       chartIndex = 8      burst = 13                  P1 = 0      P2 = 0      P3 = 28     P4 = 0          TOTAL: 125
// SKIP P2
// P3       chartIndex = 9      burst = 20                  P1 = 0      P2 = 0      P3 = 8      P4 = 0          TOTAL: 145
// SKIP P4
// SKIP P1
// SKIP P2
// P3       chartIndex = 10     burst = 8                   P1 = 0      P2 = 0      P3 = 0      P4 = 0          TOTAL: 153




// ---------------------------------------------------------------------------------------------------------------------------------------------- OTHER FUNCTIONS
int totalTime(Values value[MAX_COUNT], int processes) {

    // this function adds all the remaining burst time, if it is equal to zero, all processes are done
    int total = 0;
    for (int i = 0; i < processes; i++) {
        total += value[i].burstTime;
    }

    return total;
}

void bubbleSort(Values value[MAX_COUNT], int processes) {

    int i, j, temp1, temp2;
    for (i = 0; i < processes - 1; i++) {
        for (j = 0; j < processes - i - 1; j++) {
            if (value[j].burstTime > value[j + 1].burstTime) {
                temp1 = value[j].burstTime;
                temp2 = value[j].processNum;

                value[j].burstTime = value[j + 1].burstTime;
                value[j].processNum = value[j + 1].processNum;

                value[j + 1].burstTime = temp1;
                value[j + 1].processNum = temp2;
            }
        }
    }
    
}

int results(Values value[MAX_COUNT], int processes) {

    int burstArray[MAX_COUNT], turnaroundArray[MAX_COUNT], waitingArray[MAX_COUNT];     // arrays
    float turnaroundSum = 0, waitingSum = 0;                                            // sums
    int currentBurst = 0;                                                               // burst tracker

    printf("\n\tGANTT CHART\n");                                                        // determines at what time each process started
    for (int i = 0; i < processes; i++) {
        printf("\tP%d", value[i].processNum);
    }
    printf("\n");
    for (int i = 0; i < processes + 1; i++) {

        if (i == 0) {   // Process 1
            burstArray[i] = currentBurst;
            waitingArray[i] = currentBurst;                                             // start time of current process, is the end time of previous process
            value[i].idleTime = 0;
        }
        else {
            currentBurst += value[i - 1].burstTime;                                     // current burst of current process is tracked by adding each burst
            burstArray[i] = currentBurst;                                               // every burst is stored in an array

            turnaroundArray[i - 1] = currentBurst - value[i - 1].arrivalTime;           // turnaround time of every process is stored in an array
            waitingArray[i] = currentBurst - value[i].arrivalTime;                                             // waiting time of a process is the sum of previous bursts
        }
        printf("\t%d", currentBurst);
    }
    
    printf("\n\nTurnaround Times:");
    for (int i = 0; i < processes; i++) {
        printf("\nP%d: %d", value[i].processNum, turnaroundArray[i]);
        turnaroundSum += turnaroundArray[i];
    }

    printf("\n\nWaiting Times:");
    for (int i = 0; i < processes; i++) {
        printf("\nP%d: %d", value[i].processNum, waitingArray[i]);
        waitingSum += waitingArray[i];
    }

    printf("\n\n\t** Average Turnaround Time:\t%.6f **", turnaroundSum/processes);
    printf("\n\t** Average Waiting Time:\t%.6f **\n", waitingSum/processes);

}
