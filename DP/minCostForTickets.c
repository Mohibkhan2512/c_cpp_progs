#include <stdio.h>
#include <stdlib.h>

int costs[] = {2, 7, 15};
int ticketsForDays[] = {1, 7, 30};

int minCost(int a, int b, int c) {
    printf("Finding min cost for %d, %d, %d >>\n", a, b, c);
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int minCostForTickets(int* arr, int size, int arrSizeMax, int curDay, int ticketForDays, int cost, int* memArr) {
    int nextDay = curDay;
    puts("=======================");
    printf("curDay >> %d\n", curDay);
    printf("ticketForDays >> %d\n", ticketForDays);
    printf("cost >> %d\n", cost);

    if ((ticketForDays + curDay) > arrSizeMax) {
        printf("if true for >> %d, returning cost %d\n", ticketForDays + curDay, cost);
        return cost;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] >= ticketForDays + curDay) {
            nextDay = arr[i];
            break;
        }
    }

    printf("nextDay >> %d\n", nextDay);

    if (memArr[nextDay] != 0) {
        printf("memArr[nextDay] != 0 >> %d, cost >> %d \n", memArr[nextDay], cost);
        return memArr[nextDay] + cost;
    }

    memArr[nextDay] = minCost(
        minCostForTickets(arr, size, arrSizeMax, nextDay, ticketsForDays[2], costs[2], memArr),
        minCostForTickets(arr, size, arrSizeMax, nextDay, ticketsForDays[1], costs[1], memArr),
        minCostForTickets(arr, size, arrSizeMax, nextDay, ticketsForDays[0], costs[0], memArr)
    );

    printf("Min cost is %d, for day >> %d\n", memArr[nextDay], nextDay);
    
    return memArr[nextDay]+cost;
}

int main(int argc, char *argv[]) {
    // int arr[] = {1, 8, 20};
    int arr[] = {1, 4, 6, 7, 8, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arrSizeMax = arr[size - 1];
    puts("=======================");
    printf("arrSizeMax >> %d\n", arrSizeMax);
    int memArr[arrSizeMax + 1];
    int sizeOfMemArr = sizeof(memArr) / sizeof(memArr[0]);

    printf("sizeOfMemArr >> %d\n", sizeOfMemArr);

    for (int i = 0; i < sizeOfMemArr; i++) {
        memArr[i] = 0;
    }

    int minCostForTravelling = minCost(
        minCostForTickets(arr, size, arrSizeMax, arr[0], ticketsForDays[2], costs[2], memArr),
        minCostForTickets(arr, size, arrSizeMax, arr[0], ticketsForDays[1], costs[1], memArr),
        minCostForTickets(arr, size, arrSizeMax, arr[0], ticketsForDays[0], costs[0], memArr)
    );

    printf("minCostForTravelling >> %d\n", minCostForTravelling);

    return EXIT_SUCCESS;
}