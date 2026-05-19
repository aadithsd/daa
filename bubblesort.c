#include<stdio.h>
#include<time.h>

void sort(int arr[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
	sort(arr,n);
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;

	printf("sorted array: ");
	for(i=0;i<n;i++)
		printf("%d, ",arr[i]);
	printf("time taken: %f", cpu_time);

	return 0;
}
