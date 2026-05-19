#include<stdio.h>
#include<limits.h>
#define max 10

int graph[max][max];
int visited[max];
int n;

int tsp(int city, int count, int cost)
{
    int mincost=INT_MAX;
    int i,tcost;

    if(count==n && graph[city][0])
        return cost+graph[city][0];

    for(i=0;i<n;i++)
    {
        if(!visited[i] && graph[city][i])
        {
            visited[i]=1;
            tcost=tsp(i, count+1, cost+graph[city][i]);
            if(tcost<mincost)
                mincost=tcost;
            visited[i]=0;
        }
    }
    return mincost;
}

int main()
{
    int i,j,min;
    printf("enter number of cities: ");
    scanf("%d",&n);
    printf("enter cost matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    visited[0]=1;
    min=tsp(0,1,0);
    printf("min cost: %d",min);
    return 0;
}
