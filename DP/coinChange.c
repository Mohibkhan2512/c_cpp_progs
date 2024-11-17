#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int coinChange(int* coins, int remAmount, int coinIndex, int* memArr[]) {
    // puts("========================");

    if (remAmount == 0){
        return 1;
    }
    else if(remAmount < 0){
        return 0;
    }
    else if(coinIndex <= 0){
        return 0;
    }
    else if(memArr[coinIndex][remAmount] != -1){
        return memArr[coinIndex][remAmount];
    }

    memArr[coinIndex][remAmount] = (coinChange(coins, remAmount-coins[coinIndex-1], coinIndex, memArr) + 
                                    coinChange(coins, remAmount, coinIndex-1, memArr));
    
    return memArr[coinIndex][remAmount];
}


int main (int argc, char *argv[]) {
    int amount = 5;
    int coins[] = {1, 2, 3};
    int size = sizeof(coins)/sizeof(coins[0]);

    int rows = size+1, cols = amount+1;
    int **array = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = -1;
        }
    }  

    int numOfWays = coinChange(coins, amount, size, array);
    printf("Unique numOfWays :>> %d\n", numOfWays);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return EXIT_SUCCESS;
}


// max no of ways

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// int coinChange(int* coins, int size, int remAmount, int* memArr, int (*seqArr)[amount+1]) {
//     puts("========================");
    
//     printf("remAmount :>> %d\n", remAmount);

//     if (remAmount == 0) {
//     printf("return 1 :>>\n");
//     return 1;
//     } 
//     if (remAmount < 0) {
//         printf("return 0 :>>\n");
//         return 0;
//     }
//     if (memArr[remAmount] != 0) {
//         printf("memArr[remAmount] !=0 for :>> %d\n", remAmount);

//         // return memArr[remAmount]+remAmount;
//         return memArr[remAmount];
//         // return 1;
//     }

//     int output = -1;
//     for(int i = 0; i < size; i++) {
//         // if (coinChange(coins, size, remAmount - coins[i], memArr) == 1) {
//         //         memArr[remAmount]++;
//         // }

//         output = coinChange(coins, size, remAmount-coins[i], memArr);
//         printf("Function call made for remAmount: %d, coins[i] :>> %d\n", remAmount, coins[i]);
//         if (output == 1){
//             // if (memArr[remAmount] < (memArr[remAmount] + coins[i])){
//             //     memArr[remAmount] = memArr[remAmount] + coins[i];
//             // }
//         // if (memArr[remAmount] < output){
            
//             memArr[remAmount] += output;

//             printf("Updating %d remAmount , memArr[remAmount] :>> %d\n", remAmount,  memArr[remAmount]);
//         }
//         // if (output == 1) memArr[remAmount]++;
//     }
//     puts("#####################");
//     return memArr[remAmount];
// }


// int main (int argc, char *argv[]) {
//     int amount = 4;
//     int coins[] = {1, 2};
//     int size = sizeof(coins)/sizeof(coins[0]);
//     int memArr[amount+1];
//     int (*seqArr)[amount];

//     for (int i = 0; i < amount+1; i++) {
//         memArr[i] = 0;
//     }

//     bool changePossible = coinChange(coins, size, amount, memArr);
//     int numOfWays = 0;

//     if (changePossible){    
//         for (int i = 0; i < amount+1; i++) {
//             numOfWays += memArr[i];
//             printf("memArr[i] :>> %d\n", memArr[i]);
//         }
//     }
    
//     printf("numOfWays :>> %d\n", numOfWays);

//     return EXIT_SUCCESS;
// }