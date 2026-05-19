#include<stdio.h>
#include<conio.h>


int max(int a, int b)
{
    return (a>b)?a:b;
}

int knapsack(int wt[], int val[], int capacity, int n)
{
    int i,w;
    int dp[20][25];

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=capacity;w++)
        {
            if(i==0 || w==0)
                dp[i][w]=0;

            else if(wt[i]<=w)
                dp[i][w]=max(val[i]+dp[i-1][w-wt[i]],dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n,i,j;
    int val[20],wt[20];
    int capacity,res;

    printf("enter number of items: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("enter weight and capacity of item %d: ",i);
        scanf("%d %d",&wt[i],&val[i]);
    }

    printf("enter max capacity: ");
    scanf("%d",&capacity);

    res=knapsack(wt,val,capacity,n);
    printf("max profit: %d",res);

    return 0;
}
