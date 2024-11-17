#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int memArray[]) {
    if (n <= 1) {
        return n;
    }
    if (memArray[n] != -1) {
        return memArray[n];
    }
    memArray[n] = fibonacci(n - 1, memArray) + fibonacci(n - 2, memArray);
    return memArray[n];
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int memArray[num+1];
    for (int i = 0; i < num+1; i++) {
        memArray[i] = -1;
    }

    printf("Fibonacci of %d is %d\n", num, fibonacci(num, memArray));
    return 0;
}
