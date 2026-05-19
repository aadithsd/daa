#include<stdio.h>
#include<time.h>

void swap(int arr[], int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;

    while(1)
    {
        while(i <= high && arr[i] <= arr[pivot])
            i++;

        while(j >= low && arr[j] > arr[pivot])   // FIXED
            j--;

        if(i < j)
            swap(arr, i, j);
        else
            break;
    }

    swap(arr, pivot, j);
    return j;
}

void qs(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        qs(arr, low, pivot - 1);
        qs(arr, pivot + 1, high);
    }
}

int main()
{
    int i, n, arr[20];
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();
    qs(arr, 0, n - 1);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken: %lf", cpu_time);

    return 0;
}
