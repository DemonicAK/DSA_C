

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end)
{

    int pivot = arr[end];
    int index = (start - 1);

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(&arr[index], &arr[j]);
        }
    }
    swap(&arr[index + 1], &arr[end]);
    return (index + 1);
}

void quicksort(int arr[], int start, int end)
{

    if (start < end)
    {
        int pindex = partition(arr, start, end);
        quicksort(arr, pindex + 1, end);
        quicksort(arr, start, pindex - 1);
    }
}

void print(int arr[], int size)
{

    int n = size;
    for (int pindex = 0; pindex < n; pindex++)
    {
        printf("%d ", arr[pindex]);
    }
    printf("\n");
}

int main()
{
    int gg[13] = {9, 7, 56, 8,78,90,56,76,43,24,56789,123427,9776};
    quicksort(gg, 0, 12);

    print(gg, 13);

    return 0;
}