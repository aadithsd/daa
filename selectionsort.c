#include<stdio.h>
#include<time.h>

void selecsort(int arr[], int n)
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

    }
}
int main()
{
	int arr[50],i,n;
	double cpu_time;
	clock_t start,end;

	printf("enter number of elements: ");
	scanf("%d",&n);
	printf("\n enter array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	start=clock();
	selecsort(arr,n);
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;

	printf("sorted array: ");
	for(i=0;i<n;i++)
		printf("%d, ",arr[i]);
	printf("time taken: %f", cpu_time);

	return 0;
}
