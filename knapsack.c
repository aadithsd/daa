#include <stdio.h>
#include <conio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int wt[], int val[], int n, int capacity)
{
    int i, w;
    int dp[25][50];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(wt[i] <= w)
                dp[i][w] = max(
                    val[i] + dp[i-1][w - wt[i]],
                    dp[i-1][w]
                );

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

void main()
{
    int n, i;
    int wt[25], val[25];
    int capacity, result;

    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    result = knapsack(wt, val, n, capacity);

    printf("\nMaximum profit = %d", result);

    getch();
}
