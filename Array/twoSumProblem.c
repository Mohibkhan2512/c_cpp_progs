#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printArray (int array[], int size) {
    printf("\nEntered elements of the array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

int* takeInputFromUser(int* size, int* target){
    int s,t;
    printf("Enter size of the array: ");
    scanf("%d", &s);
    *size = s;

    // int array[size];

    int* array = (int*)malloc((*size)*sizeof(int));

    for(int i = 0; i < (*size); i++){
        printf("Enter elements of the array one by one: ");
        scanf("%d", &array[i]);
    }

    printf("Enter target to be searched in the array: ");
    scanf("%d", &t);

    *target = t;

    return array;
}

bool twoSumSolution(int array[], int size, int target){
    int twoSum = 0;

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            twoSum = array[i] + array[j];
            printf("index i: %d, j: %d, twoSum: %d\n", i, j, twoSum);
            if(twoSum == target){
                printf("Two sum found at index i: %d, j: %d\n", i, j);
                return 1;
            }
        }
    }

    return 0;
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
    size = sizeof(array) / sizeof(array[0]);

    bool sumIsPresent = twoSumSolution(array, size, target);

    if (sumIsPresent == 0){
        printf("\nThe two sum for the target is not present in the array\n");
    }
    else{
        printf("\nThe two sum for the target is present in the array\n");
    }

    /////// If array is dynamically defined by user, use free to free up after run
    // free(array);
    // array = NULL;

    return 0;
}