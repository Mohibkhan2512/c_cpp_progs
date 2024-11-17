#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int maxOfThree(int a, int b, int c){
    if (a >= b && a >= c){
        return a;
    }
    else if (b >= a && b >= c){
        return b;
    }
    return c;
}

int ninjasTrainingBottomUp(int arr[][3], int days, int totalTasks, int prevTask, int memArr[][4]){
    int maxCredit, curCredit;
    // printf("day, totalTasks, prevTask :>> %d, %d, %d\n", day, totalTasks, prevTask);
    memArr[0][0] = max(arr[0][1], arr[0][2]);
    memArr[0][1] = max(arr[0][0], arr[0][2]);
    memArr[0][2] = max(arr[0][0], arr[0][1]);
    memArr[0][3] = maxOfThree(arr[0][0], arr[0][1], arr[0][2]);

    for(int day = 1; day <= days; day++){
        maxCredit = 0;
        for (int task = 0; task <= totalTasks; task++) {
            for(int i = 0; i < totalTasks; i++){
                if(i != task){
                    curCredit = arr[day][i] + memArr[day-1][i];
                }
                memArr[day][task] = max(memArr[day][task], curCredit);
            }
        }
    }

    return memArr[days][3];
}

int ninjasTraining(int arr[][3], int day, int totalTasks, int prevTask, int memArr[][4]){
    int maxCredit = 0;
    int curCredit;
    // printf("day, totalTasks, prevTask :>> %d, %d, %d\n", day, totalTasks, prevTask);

    if (day == 0) {
        for(int i = 0; i < totalTasks; i++){
            if(i != prevTask) {
                maxCredit = max(maxCredit, arr[0][i]);
            }
        }
        return maxCredit;
    }

    if(memArr[day][prevTask] != -1) return memArr[day][prevTask];

    for(int i = 0; i < totalTasks; i++){
        if(i != prevTask){
            curCredit = arr[day][i] + ninjasTraining(arr, day-1, totalTasks, i, memArr);
        }
        maxCredit = max(maxCredit, curCredit);
    }

    return memArr[day][prevTask-1] = maxCredit;
}

int main (int argc, char *argv[]) {
    int n = 3;
    // int days = 3;
    // int totalsTasks = 3; hence, arr size => 3x3
    int arr[3][3] = {{1,2,5},{3,1,1},{3,3,3}};
    int memArr[3][3+1];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (3+1); j++) {
            memArr[i][j] = -1;
        }
    }

    // int maxCredit = ninjasTraining(arr, n-1, 3, n, memArr);
    int maxCredit = ninjasTrainingBottomUp(arr, n-1, 3, n, memArr);

    printf("maxCredit :>> %d\n", maxCredit);

    printf("memArr[i][j] :>> \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (3+1); j++) {
            printf(" %d", memArr[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}