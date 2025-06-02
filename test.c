#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int min_idx;
    int arr[n];
    for (i = 0; i < n; i++) {
        min_idx = i;
        arr[i] = rand() % 1000; // Fill array with random numbers
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    printf("%d",arr[min_idx]);
    return 0;
}