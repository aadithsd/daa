#include<stdio.h>

int parent[20];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int u, int v)
{
    parent[u] = v;
}

int main()
{
    int n, e;
    int u[20], v[20], w[20];
    int i, j, min, a, b, pos;
    int total = 0, count = 0;
    int ru, rv;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u,v,weight):\n");

    for(i = 0; i < e; i++)
        scanf("%d %d %d",
              &u[i],
              &v[i],
              &w[i]);

    // Initialize parent
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    while(count < n - 1)
    {
        min = 999;

        for(j = 0; j < e; j++)
        {
            if(w[j] < min)
            {
                min = w[j];
                a = u[j];
                b = v[j];
                pos = j;   // store position
            }
        }

        ru = find(a);
        rv = find(b);

        if(ru != rv)
        {
            printf("%d - %d = %d\n",
                   a, b, min);

            total += min;
            unionSet(ru, rv);
            count++;
        }

        w[pos] = 999; // mark used edge
    }

    printf("Min cost: %d", total);

    return 0;
}
