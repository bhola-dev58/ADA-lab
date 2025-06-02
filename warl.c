#include <stdio.h>
#define N 10     

int R[N][N];
int n,i, j, k;

void printMatrix() 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
	{
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
}

void warshall() 
{
    for (k = 0; k < n; k++) 
	{
      for (i = 0; i < n; i++) 
	{
            for (j = 0; j < n; j++) 
	{
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
        printMatrix();
    }
    printf("\nTransitive closure of the given graph:\n");
    printMatrix();
}


int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
   printf("Enter the adjacency matrix (row by row):\n");
   
   for (i = 0; i < n; i++) 
   {
           for (j = 0; j < n; j++) 
          {
               scanf("%d", &R[i][j]);
           }
       }
       warshall();
       return 0;
   }
   