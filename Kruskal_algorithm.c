#include <stdio.h>

int find(int x, int parent[]) {
while (parent[x] >= 0)
x = parent[x];
return x;
}

void setUnion(int x, int y, int parent[]) {

if (parent[x] < parent[y]) {
parent[x] += parent[y];
parent[y] = x;
} else {
parent[y] += parent[x];
parent[x] = y;
}
}

void kruskalAlgo(int edge[][3], int n) {
int i, x, y, cost = 0, ecount = 0;
int parent[n];
for (i = 0; i < n; i++)
parent[i] = -1;
i = 0;
int mst[n - 1][2];
while (i < (n * n) && ecount < n - 1) {
if (edge[i][2] == 999)
break;
x = find(edge[i][0], parent);
y = find(edge[i][1], parent);
if (x != y) {
cost += edge[i][2];
mst[ecount][0] = edge[i][0];
mst[ecount++][1] = edge[i][1];
setUnion(x, y, parent);
}
i++;
}
if (ecount < n - 1)
printf("The minimal spanning tree could not be found\n");

else {
printf("The minimal spanning tree cost: %d\n", cost);
printf("The minimal spanning tree is:\n");
for (i = 0; i < n - 1; i++)
printf("%d - %d\n", mst[i][0], mst[i][1]);
}
}

int main() {
int n, i, j, k = 0;
printf("Enter the number of vertices: ");
scanf("%d", &n);
int a[n][n];
int edge[n * n][3];
printf("Enter the adjacency matrix (999 - no edge):\n");
for (i = 0; i < n; i++){
for (j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
edge[k][0] = i;
edge[k][1] = j;
edge[k++][2] = a[i][j];
}
}
for(i=0;i<n*n;i++){
for(j=0;j<=3;j++){
printf("%d ",edge[i][j]);
}
printf("\n");
}

// Sorting the edges based on their weights

for (i = 0; i < n * n; i++)
for (j = 0; j < n * n - i - 1; j++)
if (edge[j][2] > edge[j + 1][2]) {
int temp[3];
for (k = 0; k < 3; k++)
temp[k] = edge[j][k];
for (k = 0; k < 3; k++)
edge[j][k] = edge[j + 1][k];
for (k = 0; k < 3; k++)
edge[j + 1][k] = temp[k];
}
kruskalAlgo(edge, n);
return 0;
}