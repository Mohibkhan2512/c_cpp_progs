#include <stdio.h>
#include <stdlib.h>

int maxTwoNums(int one, int two){
    return one >= two ? one : two;
}

int minTwoNums(int one, int two){
    return one <= two ? one : two;
}

int maxProfitFromStockBuyAndSell(int* arr, int arrSize){
    int minValueDay = arr[0];
    int maxProfit = 0;
    int profitOnSell = 0;

    for (int i = i; i < arrSize; i++) {
        profitOnSell = arr[i]-minValueDay;
        maxProfit = maxTwoNums(maxProfit, profitOnSell);
        minValueDay = minTwoNums(arr[i], minValueDay);
    }

    return maxProfit;

}

int main (int argc, char *argv[]) {
    int arr[] = {7,1,5,3,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int maxProfit = maxProfitFromStockBuyAndSell(arr, size);

    printf("maxProfit :>> %d\n", maxProfit);

    return EXIT_SUCCESS;
}