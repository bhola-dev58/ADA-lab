#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];  
int visited[MAX];  
int recStack[MAX];  // Check Cycle
int stack[MAX];      
int top = -1;        
int vertices;
int isCyclic = 0;    // Check Cycle
void dfs(int v) 
{
    visited[v] = 1;
    recStack[v] = 1;
    for (int i = 0; i < vertices; i++) 
    {
        if (adj[v][i])
        {
            if (!visited[i]) 
            {
                dfs(i);
                if (isCyclic) return; // Check Cycle
            } 
            else if (recStack[i]) 
            { // Check Cycle
                isCyclic = 1; // Check Cycle
                return; // Check Cycle
            }
        }
    }
    recStack[v] = 0; // Check Cycle
    stack[++top] = v;
}
void topologicalSort() {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
            if (isCyclic) break; // Check Cycle
        }
    }

    if (isCyclic) 
    { // Check Cycle
        printf("The graph is not a DAG. Topological sort not possible.\n");
    } 
    else 
    {
        printf("Topological Sort Order: ");
        while (top != -1) 
        {
            printf("%d ", stack[top--]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &adj[i][j]);
    topologicalSort();
    return 0;
