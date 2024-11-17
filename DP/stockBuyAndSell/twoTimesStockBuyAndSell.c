#include <stdio.h>
#include <stdlib.h>

int maxTwoNums(int one, int two){
    return one >= two ? one : two;
}

int twoTimesStockBuyAndSellBottomUp(int* prices, int arrSize, int maxBuyAndSell, int*** memArr) {
    int i, j, k;
    for (i = arrSize - 1; i >= 0; i--) {
        for (j = 0; j <= 1; j++) {
            for (k = 1; k <= maxBuyAndSell; k++) {
                if (j == 1) {
                    memArr[i][j][k] = maxTwoNums(memArr[i + 1][0][k] - prices[i],
                                                 memArr[i + 1][1][k]);
                }
                else {
                    memArr[i][j][k] = maxTwoNums(memArr[i + 1][1][k-1] + prices[i],
                                                     memArr[i + 1][0][k]);
                }
            }
        }
    }

    // return memArr[0][1][2]; 
    // printf("i, j, k :>> %d, %d, %d\n", i, j, k); // i, j, k :>> -1, 2, 3
    return memArr[i+1][j-1][k-1]; 
}

int twoTimesStockBuyAndSellMemoization(int* prices, int arrSize, int curIdx, int buy, int maxBuyAndSell, int*** memArr) {
    if (curIdx == arrSize) return 0;
    if (memArr[curIdx][buy][maxBuyAndSell] != 0) return memArr[curIdx][buy][maxBuyAndSell];
    if (maxBuyAndSell == 0) return 0;
    
    if (buy == 1) {
        memArr[curIdx][buy][maxBuyAndSell] = maxTwoNums(twoTimesStockBuyAndSellMemoization(prices, arrSize, curIdx+1, 0, maxBuyAndSell, memArr) - prices[curIdx],
                                                        twoTimesStockBuyAndSellMemoization(prices, arrSize, curIdx+1, 1, maxBuyAndSell, memArr));
    }
    else {
        memArr[curIdx][buy][maxBuyAndSell] = maxTwoNums(twoTimesStockBuyAndSellMemoization(prices, arrSize, curIdx+1, 1, maxBuyAndSell-1, memArr) + prices[curIdx],
                                                        twoTimesStockBuyAndSellMemoization(prices, arrSize, curIdx+1, 0, maxBuyAndSell, memArr));
    }

    return memArr[curIdx][buy][maxBuyAndSell];
}

void printMemArr(int*** memArr, int arrSize, int maxAllowedBuy, int maxBuyAndSell) {
    for (int i = 0; i <= arrSize; i++) {
        printf("memArr[%d]:\n", i);
        for (int j = 0; j <= maxAllowedBuy; j++) {
            printf("  Buy %d: ", j);
            for (int k = 0; k <= maxBuyAndSell; k++) {
                printf("%d ", memArr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main (int argc, char *argv[]) {
    // int arr[] = {7,1,5,3,6,4};
    int arr[] = {3,3,5,0,0,3,1,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maxBuyAndSell = 2;

    int*** memArr = malloc((size+1)*sizeof(int**));

    for (int i = 0; i <= size; i++) {
        memArr[i] = malloc(3*sizeof(int*));
        for (int j = 0; j <= 2; j++) {
            memArr[i][j] = malloc((maxBuyAndSell+1)*sizeof(int));
            for (int k = 0; k <= maxBuyAndSell; k++) {
                memArr[i][j][k] = 0;
            }
        }
    }

    // int maxProfit = twoTimesStockBuyAndSellMemoization(arr, size, 0, 1, maxBuyAndSell, memArr);
    
    int maxProfit = twoTimesStockBuyAndSellBottomUp(arr, size, maxBuyAndSell, memArr);

    printf("maxProfit :>> %d\n", maxProfit);

    // printMemArr(memArr, size, 2, maxBuyAndSell);

    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= 2; j++) {
            // Free each inner array
            free(memArr[i][j]);
        }
        // Free the array of pointers for each i
        free(memArr[i]);
    }
    // Finally, free the outer array
    free(memArr);


    return EXIT_SUCCESS;
}