#include <stdio.h>
#include <conio.h>
#include <time.h>

#define MAX 50

void merge(int arr[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	int temp[MAX];   /* Fixed size array for Turbo C */

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];

	while (j <= high)
		temp[k++] = arr[j++];

	for (i = low, k = 0; i <= high; i++, k++)
		arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void main()
{
	int arr[MAX], i, n;
	double cpu_time;
	clock_t start, end;

	clrscr();

	printf("Enter number of elements (max 50): ");
	scanf("%d", &n);

	printf("Enter array elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	start = clock();
	mergeSort(arr, 0, n - 1);
	end = clock();

	cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nSorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n\nTime taken: %lf seconds\n", cpu_time);

	getch();
}
