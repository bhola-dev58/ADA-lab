#include <stdio.h>
#define N 10       

int D[N][N];       
int n,i,j,k;
int matrix[N][N];             

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

void printMatrix() 
{
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
	{
               printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void floyd() 
{
      for (k = 0; k < n; k++) 
	{
        for (i = 0; i < n; i++) 
	{
            for (j = 0; j < n; j++) 
	    {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
        printMatrix();
    }
    printf("\nAll-pairs shortest path matrix:\n");
    printMatrix();
}

int main() 
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 99 for no direct edge and 0 for same vertex):\n");
    for (i = 0; i < n; i++) 
   {
        for (j = 0; j < n; j++) 
       {
            scanf("%d", &D[i][j]);
        }
    }
    floyd();
    return 0;
}
