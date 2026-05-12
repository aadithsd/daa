#include<stdio.h>
#include<conio.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int knapsack(int wt[], int val[] , int n, int W)
{
    int i,w;
    int dp[25][50];   

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w]=0;

            else if(wt[i] <= w)
                dp[i][w] = max(
                    val[i] + dp[i-1][w-wt[i]],
                    dp[i-1][w]
                );

            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

void main()
{
    int n,i,wt[25],val[25],W,res;

    clrscr();

    printf("Enter number of items: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("Enter weight and profit of item %d: ",i);
        scanf("%d %d",&wt[i],&val[i]);
    }

    printf("Enter capacity: ");
    scanf("%d",&W);

    res = knapsack(wt,val,n,W);

    printf("\nMaximum profit = %d",res);

    getch();
}
