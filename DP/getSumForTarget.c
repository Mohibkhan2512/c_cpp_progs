#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool getSumForTarget(int* arr, int size, int targetSum){
    for (int i = 0; i < size; i++){
        if (targetSum == 0) return true;
        if (targetSum < 0) return false;
        else{
            if (getSumForTarget(arr, size, targetSum - arr[i]) == true){
                return true;
            }
        }
    }

    return false;
}

int main (int argc, char *argv[]) {
    int arr[] = {5,3,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 7;

    bool SumPresent = getSumForTarget(arr, size, targetSum);
    printf("SumPresent :>> %d\n", SumPresent);

    return EXIT_SUCCESS;
}