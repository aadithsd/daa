#include<stdio.h>
#include<conio.h>

#define max 10

int adj[max][max], v[max];
int f = -1, r = -1;
int q[max];

void enque(int x)
{
    if(r == max - 1)
        return;

    if(f == -1)
        f = 0;

    q[++r] = x;
}

int deque()
{
    if(f == -1 || f > r)
        return -1;

    return q[f++];
}

void bfs(int n, int start, int adj[max][max])
{
    int i, node;

    enque(start);
    v[start] = 1;

    printf("BFS TRAVERSAL:\n");

    while(f <= r)
    {
        node = deque();
        printf("%d ", node);

        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1 && !v[i])
            {
                enque(i);
                v[i] = 1;
            }
        }
    }
}

void main()
{
    int i, j, start, n;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for(i = 0; i < n; i++)
        v[i] = 0;

    printf("Enter start vertex: ");
    scanf("%d", &start);

    bfs(n, start, adj);

    getch();
}
