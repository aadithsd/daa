#include<stdio.h>
int parent[20];

int find(int i)
{
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

void unionSet(int u, int v)
{
    parent[u]=v;
}

int main()
{
    int n,e;
    int u[20],v[20],w[20];
    int i,j,min,a,b;
    int total=0;
    int ru,rv;

    printf("enter number of vertices: ");
    scanf("%d",&n);
    printf("enter number of edges: ");
    scanf("%d",&e);

    printf("enter edges (u,v,weight): ");
    for(i=0;i<e;i++)
        scanf("%d %d %d",&u[i],&v[i],&w[i]);

    for(i=0;i<n;i++) // find parent
        parent[i]=i; //initially each node is its own parent

    printf("edges in mst: \n");
    for(i=0;i<n-1;i++)
    {
        min=999;
        for(j=0;j<e;j++)
        {
            if(w[j]<min)
            {
                min=w[j];
                a=u[j];
                b=v[j];
            }
        }
        ru=find(a);
        rv=find(b);

        if(ru!=rv)
        {
            printf("%d - %d = %d",a,b,min);
            total+=min;
            unionSet(ru,rv);
        }
        w[j-1]=999;


    }
    printf("min cost: %d",total);

}
