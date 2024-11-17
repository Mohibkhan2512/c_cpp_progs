#include <stdio.h>
#include <stdlib.h>

void mergeSubArrayToMain(int* leftSubArr, int* rightSubArr, int arr[], int nLSA, int nRSA){
    puts("call to merge sub arr");
    int iLSA = 0;
    int iRSA = 0;
    int iMA = 0;

    printf("%d, %d :>> \n", nLSA, nRSA);

    for(int i = 0; i < nLSA; i++){
        printf("val %d in LSA: \n", leftSubArr[i]);
    }

    for(int i = 0; i < nRSA; i++){
        printf("val %d in RSA: \n", rightSubArr[i]);
    }

    while (iLSA < nLSA && iRSA < nRSA){
        if (leftSubArr[iLSA] <= rightSubArr[iRSA]){
            arr[iMA] = leftSubArr[iLSA];
            printf("updating %d, index: %d with %d, index %d : \n", arr[iMA], iMA, leftSubArr[iLSA], iLSA);
            iLSA++;
        }
        else{
            arr[iMA] = rightSubArr[iRSA];
            printf("updating %d, index: %d with %d, index %d : \n", arr[iMA], iMA, leftSubArr[iRSA], iRSA);
            iRSA++;
        }
        iMA++;
    }

    while(iLSA < nLSA){
        arr[iMA] = leftSubArr[iLSA]; iMA++; iLSA++;
    }

    while(iRSA < nRSA){
        arr[iMA] = rightSubArr[iRSA]; iMA++; iRSA++;
    }
    puts("Going out of merge\n====================");
}

void mergeSort(int arr[], int size){
    // if (size < 2){
    //     return;
    // }

    if (size >= 2){
        int mid = size/2;  
        printf("size: %d, mid: %d \n", size, mid);
        int leftSubArr[mid];
        int rightSubArr[size-mid];
        
        for(int i = 0; i < mid; i++){
            leftSubArr[i] = arr[i];
        }
        for(int j = mid; j < size; j++){
            rightSubArr[j-mid] = arr[j];
        }

        mergeSort(leftSubArr, mid);
        mergeSort(rightSubArr, size-mid);

        puts("Before calling to merge");
        for(int i = 0; i < mid; i++){
            printf("val %d in LSA: \n", leftSubArr[i]);
        }

        for(int i = 0; i < size-mid; i++){
            printf("val %d in RSA: \n", rightSubArr[i]);
        }
        puts("====================");
        mergeSubArrayToMain(leftSubArr, rightSubArr, arr, mid, size-mid);
    }
}

void mainFunctionForMergeSort(int* arr, int size){
    mergeSort(arr, size);
}

int main (int argc, char *argv[]) {
    int arr[] = {5,1,4,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    mainFunctionForMergeSort(arr, size);

    puts("Sorted array: ");
    for (int i = 0; i < size; i++){
        printf("%d ",  arr[i]);
    }
    puts("\n");

    return EXIT_SUCCESS;
}