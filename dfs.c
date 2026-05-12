#include<stdio.h>
#include<conio.h>
#define MAX 10
int visited[MAX];
int n;
int adj[MAX][MAX];

void DFS(int v)
{
    int i;
    printf("%d->",v);
    visited[v]=1;
    for(i=0;i<n;i++){
            if(adj[v][i] == 1 && !visited[i]){
                DFS(i);
            }
    }
}


void main()
{
  int start,i,j;
  printf(" Depth first search\n");
  printf("enter the number of vertices :");
  scanf("%d",&n);
  printf("enter the adjacency matrix: \n");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    scanf("%d",&adj[i][j]);
    printf("enter starting vertex : ");
    scanf("%d",&start);
    printf("DFS Traversal :\n ");
    DFS(start);
    getch();
}

