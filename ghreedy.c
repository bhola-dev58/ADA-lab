#include <stdio.h>
#define max 100

typedef struct {
	float weight;
	float value;
	float ratio;
} item;
item a[max];
int n;
float capacity;

void bubbleSort()
{
	int i, j;
	item temp;
	for (i = 0; i < n - 1; i++)
 {
    	for (j = 0; j < n - i - 1; j++)	
 {
        	if (a[j].ratio < a[j + 1].ratio) 
{
            	temp = a[j];
            	a[j] = a[j + 1];
            	a[j + 1] = temp;
        	}
    	}
	}
}

void discrete()
 {
	int i;
	float total = 0;  
	int rem=capacity;
	for (i = 0; i < n; i++) 
{
    	if (rem >= a[i].weight)
 {
        		rem = rem-a[i].weight;
        		total= tota+a[i].value;
    	}
    	}
    	printf("Total value in Discrete Knapsack: %f \n",totalValue);
}
    
void fractional() {
	int i;
	float total = 0;
	float rem = capacity;
    	for (i = 0; i < n; i++)
{
    	if (rem >= a[i].weight)
 {
        		rem=rem-a[i].weight;
        		total=total+ a[i].value;
    	} 
else 
{
        		total = total+(rem / a[i].weight) * a[i].value;
        		break;
    	}
	}
    
	printf("Total value in Fractional Knapsack: %f \n", totalValue);
}

int main() {
	int i;
	printf("Enter the capacity: ");
	scanf("%f", &capacity);
	printf("Enter the number of items: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
{
    		printf("Enter the weight of item %d: ", i + 1);
    	scanf("%f", &a[i].weight);
    	printf("Enter the value of item %d: ", i + 1);
    	scanf("%f", &a[i].value);
    	a[i].ratio = a[i].value / a[i].weight;
	}
 	bubbleSort();

	printf("Sorted items based on ratio:\n");
	for (i = 0; i < n; i++)
 {
    		printf("%f %f %f \n", a[i].weight, a[i].value, a[i].ratio);
	}
	discrete();
	fractional();
	return 0;
}

