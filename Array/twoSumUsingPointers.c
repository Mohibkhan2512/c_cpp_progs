#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mergeSortedArrays(int* arr, int* LSA, int* RSA, int nLSA, int nRSA){
    int iLSA = 0;
    int iRSA = 0;
    int iArr = 0;

    while(iLSA < nLSA && iRSA < nRSA){
        if(LSA[iLSA] < RSA[iRSA]){
            arr[iArr] = LSA[iLSA];
            iLSA++;
        }
        else{
            arr[iArr] = RSA[iRSA];
            iRSA++;
        }
        iArr++;
    }

    while(iLSA < nLSA){
        arr[iArr] = LSA[iLSA];
        iArr++; iLSA++;
    }

    while(iRSA < nRSA){
        arr[iArr] = RSA[iRSA];
        iArr++; iRSA++;
    }
}

void mergeSort(int* arr, int size){
    if (size >= 2){
        int mid = size/2;
        int LSA[mid];
        int RSA[size-mid];

        for (int i = 0; i < mid; i++){
            LSA[i] = arr[i];
        }

        for (int j = mid; j < size; j++){
            RSA[j-mid] = arr[j];
        }

        mergeSort(LSA, mid);
        mergeSort(RSA, size-mid);
        mergeSortedArrays(arr, LSA, RSA, mid, size-mid);
    }
}

bool twoSumSolutionUsingPointer(int* arr, int size, int target){
    mergeSort(arr, size);

    printf("Sorted Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    int* pLeft = &arr[0]; // same as => arr
    int* pRight = &arr[size]; // same as => arr + size
    int sum;

    while (*pLeft < *pRight){
        sum = *pLeft + *pRight;
        if (sum == target) return 1;
        else if (sum < target) pLeft++;
        else pRight--;
    }

    return 0;
}

int* twoSumSolutionUsingPointerGetIndexOnMatch(int* arr, int* indexArr, int size, int target){
    mergeSort(arr, size);

    int iLeftPoniter = 0;
    int iRightPoniter = size-1;
    // printf("initially iLeftPoniter :>> %d, iRightPoniter :>> %d\n", iLeftPoniter, iRightPoniter);

    printf("Sorted Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    int* pLeft = &arr[0]; // same as => arr
    int* pRight = &arr[size-1]; // same as => arr + size
    int sum;

    while (*pLeft < *pRight){
        sum = *pLeft + *pRight;
        printf("\nCur sum :>> %d\n", sum);

        if (sum == target) {
            printf("iLeftPoniter :>> %d, iRightPoniter :>> %d\n", iLeftPoniter, iRightPoniter);
            indexArr[0] = iLeftPoniter;
            indexArr[1] = iRightPoniter;

            return indexArr;
        }
        else if (sum < target) {
            pLeft++; iLeftPoniter++;
            printf("incr iLeftPoniter to :>> %d\n", iLeftPoniter);

        }
        else {
            pRight--; iRightPoniter--;
            printf("decr iRightPoniter to :>> %d\n", iRightPoniter);

        }
    }

    return indexArr;
}

int main (int argc, char *argv[]) {
    int size, target;

    /////// Function to take array, size and target input from user
    // int* array = takeInputFromUser(&size, &target);
    
    /////// Function to print the content of the input array
    // printArray(array, size);

    /////// Manually defining the array, size and target
    int array[] = {2,6,5,8,11}; 
    target = 15;
    target = 14;
    size = sizeof(array) / sizeof(array[0]);

    bool sumIsPresent = twoSumSolutionUsingPointer(array, size, target);

    if (sumIsPresent == 0){
        printf("\nThe two sum for the target is not present in the array\n");
    }
    else{
        printf("\nThe two sum for the target is present in the array\n");
    }

    int indexArr[] = {-1, -1};

    int* indexOfMatches = twoSumSolutionUsingPointerGetIndexOnMatch(array, indexArr, size, target);

    if(*indexOfMatches == -1 || *(indexOfMatches+1) == -1){
        printf("\nThe two sum for the target is not present in the array\n");
    }
    else{
        printf("\nThe two sum for the target is present in the array at \
        index: %d, %d\n", *indexOfMatches, *(indexOfMatches+1));
    }

    /////// If array is dynamically defined by user, use free to free up after run
    // free(array);
    // array = NULL;

    return EXIT_SUCCESS;
}