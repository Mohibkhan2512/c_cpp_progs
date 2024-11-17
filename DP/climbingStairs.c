#include <stdio.h>
#include <stdlib.h>

int climbingStairs(int nSteps, int* memArry){
    if (nSteps < 0) return 0;
    if (nSteps == 0) return 1;

    if(memArry[nSteps] != -1){
        return memArry[nSteps];
    }

    memArry[nSteps] = ( climbingStairs(nSteps-1, memArry) +
                        climbingStairs(nSteps-2, memArry) );

    return memArry[nSteps];
}

int main (int argc, char *argv[]) {
    int nSteps = 4;
    // nSteps+1 because we want to store data for steps 0-4, 
    // i.e.; 0,1,2,3,4 => 5 entries
    int memArry[nSteps+1]; 

    for (int i = 0; i < nSteps+1; i++) {
        memArry[i] = -1;
    }

    int nWays = climbingStairs(nSteps, memArry);
    printf("nWays :>> %d\n", nWays);

    return EXIT_SUCCESS;
}