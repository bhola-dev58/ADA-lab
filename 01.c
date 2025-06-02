#include <stdio.h>

int values[100], weights[100]; 
int dp[100][100];
int n, capacity;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void print_dp_table() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

void knapsack_01() {
    
    for (int j = 0; j <= capacity; j++) dp[0][j] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i - 1][j], values[i] + dp[i - 1][j - weights[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    print_dp_table();

   
    int rem_cap = capacity;
    printf("\nThe selected items: ");
    for (int i = n; i > 0 && rem_cap > 0; i--) {
        if (dp[i][rem_cap] != dp[i - 1][rem_cap]) {
            printf("%d ", i);
            rem_cap -= weights[i];
        }
    }

    printf("\nMaximum value: %d\n", dp[n][capacity]);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 1; i <= n; i++) {
        printf("Enter value and weight for item %d: ", i);
        scanf("%d %d", &values[i], &weights[i]);
    }

    knapsack_01();
    return 0;
}
