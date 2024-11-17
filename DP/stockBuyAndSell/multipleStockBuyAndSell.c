#include <stdio.h>
#include <stdlib.h>

int maxTwoNums(int one, int two){
    return one >= two ? one : two;
}

int multipleStockBuyAndSellRecursive(int* prices, int arrIdx, int arrSize, int buy){
    if(arrIdx == arrSize) return 0;
    int profit = 0;
    if(buy == 1){
        profit = maxTwoNums(multipleStockBuyAndSellRecursive(prices, arrIdx+1, arrSize, 0) - prices[arrIdx], //buy 
                            multipleStockBuyAndSellRecursive(prices, arrIdx+1, arrSize, 1) - 0); // not buy
    } else{ // sell
        profit = maxTwoNums(multipleStockBuyAndSellRecursive(prices, arrIdx+1, arrSize, 1) + prices[arrIdx], //sell 
                            multipleStockBuyAndSellRecursive(prices, arrIdx+1, arrSize, 0) + 0); // not sell
    }

    return profit;
}

int multipleStockBuyAndSellMemoization(int* prices, int arrIdx, int arrSize, int buy, int** memArr){
    if (arrIdx == arrSize) return 0;
    if (memArr[arrIdx][buy] != -1) return memArr[arrIdx][buy];
    // int profit = 0;
    if (buy == 1) { // stock not bought previously
        memArr[arrIdx][buy] = maxTwoNums(multipleStockBuyAndSellMemoization(prices, arrIdx+1, arrSize, 0, memArr) - prices[arrIdx], //buy 
                            multipleStockBuyAndSellMemoization(prices, arrIdx+1, arrSize, 1, memArr) - 0); // not buy
    } else {// stock bought previously
        memArr[arrIdx][buy] = maxTwoNums(multipleStockBuyAndSellMemoization(prices, arrIdx+1, arrSize, 1, memArr) + prices[arrIdx], //sell 
                            multipleStockBuyAndSellMemoization(prices, arrIdx+1, arrSize, 0, memArr) + 0); // not sell
    }

    return memArr[arrIdx][buy];
}

int multipleStockBuyAndSellBottomUp(int* prices, int arrIdx, int arrSize, int maxBuy, int** memArr){
    int maxProfit = 0;

    for (int i = 1; i <= arrSize; i++) {
        for (int j = 1; j <= 2; j++) {
            if (j == 2) { // stock not bought previously
                memArr[i][j] = maxTwoNums(memArr[i][j] - prices[i-1], //buy 
                                          memArr[i][j-1] - 0); // not buy
            } else {// stock bought previously
                memArr[i][j] = maxTwoNums(memArr[i][j] + prices[i-1], //sell 
                                          memArr[i][j-1] + 0); // not sell
            }
            maxProfit = maxTwoNums(maxProfit, memArr[i][j]);
        }
    }    

    return maxProfit;
}

int main (int argc, char *argv[]) {
    int arr[] = {7,1,5,3,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    /** for memoization **/
    // int** memArr = malloc(size*sizeof(int**));
    // for (int i = 0; i < size; i++) {
    //     memArr[i] = malloc(2*sizeof(int)); // two choices 0 -> buy or 1 -> don't buy
    //     for (int j = 0; j < 2; j++) {
    //         memArr[i][j] = -1;
    //     }
    // }

    //for bottomUp
    int** memArr = malloc((size+1)*sizeof(int**));
    for (int i = 0; i <= size; i++) {
        memArr[i] = malloc(3*sizeof(int)); // two choices 0 -> base-case, 1 -> buy or 2 -> don't buy
        for (int j = 0; j <= 2; j++) {
            memArr[i][j] = 0;
        }
    }

    /** for recursive approach **/
    // int maxProfit = multipleStockBuyAndSellRecursive(arr, 0, size, 1);

    /** for memoization **/
    // int maxProfit = multipleStockBuyAndSellMemoization(arr, 0, size, 1, memArr);

    for (int i = 0; i <= size; i++) {
        memArr[i][0] = 0;
    }

    for (int j = 0; j <= 2; j++) {
        memArr[0][j] = 0;
    }

    int maxProfit = multipleStockBuyAndSellBottomUp(arr, 0, size, 2, memArr);

    printf("maxProfit :>> %d\n", maxProfit);

    puts("Mem table after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}