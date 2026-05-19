#include<stdio.h>
#define max 10

typedef struct
{
	int weight, profit;
	float ratio;
}items;

void sortItems(items item[], int n)
{
	int i,j;
	items temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(item[j].ratio<item[j+1].ratio)
			{
				temp=item[j];
				item[j]=item[j+1];
				item[j+1]=temp;
			}
		}
	}
}

float knapsack(items item[], int n, int capacity)
{
	int i;
	float tp=0.0;

	for(i=0;i<n;i++)
	{
		if(capacity>=item[i].weight)
		{
			capacity-=item[i].weight;
			tp+=item[i].profit;
		}
		else
		{
			tp+=item[i].ratio*capacity;
			break;
		}

	}
	return tp;
}

int main()
{
	int i,n,capacity;
	items item[max];
	float p;

	printf("enter number of items: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("enter weight and profit of item %d: ",i+1);
		scanf("%d %d",&item[i].weight,&item[i].profit);
		item[i].ratio=(float)item[i].profit/item[i].weight;
	}

	sortItems(item,n);
	printf("\nEnter maximum capacity: ");
	scanf("%d",&capacity);
	p=knapsack(item,n,capacity);
	printf("\nMaximum profit: %.2f",p);
	return 0;
}
