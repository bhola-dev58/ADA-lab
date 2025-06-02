#include <stdio.h>
int A[100], n, d;
int anyFound = 0;  
void subsetSum(int index, int currentSum, int included[]) 
{
    if (currentSum == d)
 {
        printf("Subset found: ");
        for (int i = 0; i < n; i++) 
        {
            if (included[i])
                printf("%d ", A[i]);
        }
        printf("\n");
        anyFound = 1;
        return;
    }
    if (index == n || currentSum > d)
        return;
    included[index] = 1;
    subsetSum(index + 1, currentSum + A[index], included);

    included[index] = 0;
    subsetSum(index + 1, currentSum, included);
}
int main() 
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
  
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the target sum (d): ");
    scanf("%d", &d);
    int included[100] = {0};
    subsetSum(0, 0, included);
    if (!anyFound)
        printf("No subset found with sum %d\n", d);

    return 0;
}
