
#include<stdio.h>
#include<time.h>

void sort(int arr[], int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
