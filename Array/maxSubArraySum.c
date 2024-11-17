#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

int maxSubArraySum(int* arr, int size, int* indexes){
    int max = INT_MIN;
    int sum = 0;
    int iLeft = 0;
    int iRight;

    for(int i = 0; i < size; i++){
        sum += arr[i];

        if (max < sum) {
            max = sum;
            iRight = i;
        }
        
        if (sum < 0) {
            sum = 0;
            iLeft = i+1;
            iRight = i+1;
        }
    }

    indexes[0] = iLeft;
    indexes[1] = iRight;

    return max;
}

int main (int argc, char *argv[]) {
    // int arr[] = {-2,1,-3,4,-1,-2,1,-5,4};
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int indexes[] = {-1, -1};

    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array size :>> %d\n", size);

    printf("Max subarray sum :>> %d\n", maxSubArraySum(arr, size, indexes));
    printf("Max subarray [ %d, %d ] \n", indexes[0], indexes[1]);


    return EXIT_SUCCESS;
}