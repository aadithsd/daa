#include<stdio.h>
#define max 10

int main()
{
    int n,i,j,k;
    int adj[max][max],vi[max];
    int v,u,min;
    int total=0;

    printf("enter number of nodes: ");
    scanf("%d",&n);
    printf("enter cost matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);

            if(adj[i][j]==0)
                adj[i][j]=999;
        }
    }
    for(i=0;i<n;i++)
        vi[i]=0;

    vi[0]=1; // start from 1

    printf("edges is mst: ");

    for(k=0;k<n-1;k++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(vi[i])
            {
                for(j=0;j<n;j++)
                {
                    if(!vi[j] && adj[i][j]<min)
                    {
                        min=adj[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        printf("%d -- %d -- %d \n",u,v,min);
        total+=min;
        vi[v]=1;

    }
    printf("total cost: %d",total);
    return 0;

}
