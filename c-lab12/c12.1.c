#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct executionTime{
    char name[20];
    int countCodeRows;
    double executionTimeSGIChallenge;
    double executionTimeSGIINdy;
};
int main(){
    struct executionTime executionTime[3];
    strcpy(executionTime[0].name, "OCEAN");
    executionTime[0].countCodeRows = 1917;
    executionTime[0].executionTimeSGIChallenge = 8.7;
    executionTime[0].executionTimeSGIINdy = 18.2;

    strcpy(executionTime[1].name, "DYFESM");
    executionTime[1].countCodeRows = 3386;
    executionTime[1].executionTimeSGIChallenge = 6.95;
    executionTime[1].executionTimeSGIINdy = 22;

    strcpy(executionTime[2].name, "TRFD");
    executionTime[2].countCodeRows = 417;
    executionTime[2].executionTimeSGIChallenge = 1.05;
    executionTime[2].executionTimeSGIINdy = 2.98;


    printf("-------------------------------------------------\n");
    printf("Execution time of some programs that use parallel algorithms\n");
    printf("-------------------------------------------------\n");
    printf("| Name\t| Number of lines of code | Execution time. of SGI Callenge (sec) | Execution time. of SGI Indy (sec) |\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %s | %d | %f\t| %f\t|\n",executionTime[i].name, executionTime[i].countCodeRows, executionTime[i].executionTimeSGIChallenge, executionTime[i].executionTimeSGIINdy);
        printf("-------------------------------------------------\n");
    }
    printf("\nSGI Callenge - CP R1000 196 MHz, 1.024 MB RAM SGI Indy - CP MIPS R4600 134 MHz, 64 MB RAM ");
    return 0;
}