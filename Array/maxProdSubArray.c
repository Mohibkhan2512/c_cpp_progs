#include <stdio.h>
#include <stdlib.h>

int maxProductSubArray(int* Nums, int size){
    int subArrSize = 2;
    int max = Nums[0];
    int product;

    for (int i = 0; i < size - 1; i++){
        product = Nums[i];
        // printf("max %d for i:>> %d\n", max, i);
        for (int j = i+1; j < size; j++){            
            product = product * Nums[j];
            if (max < product){
                max = product;
            }
            printf("Product for %d, %d :>> %d\n", i, j, product);
        }
    }

    printf("max :>> %d\n",  max);
}

int main (int argc, char *argv[]) {

    // int Nums[] = {1,2,3,4,5,0};
    int Nums[] = {1,2,-3,0,-4,-5};
    int size = sizeof(Nums)/sizeof(Nums[0]);

    int maxProduct = maxProductSubArray(Nums, size);

    return EXIT_SUCCESS;
}