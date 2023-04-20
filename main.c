#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Fill(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = i + 1;
    }
}

void Swap(int arr[], int size, int num)
{
    int temp = arr[num];
    arr[num] = arr[size - 1];
    arr[size - 1] = temp;
}

void Show(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void HeapPermute(int arr[], int n, int size)
{
    if (size == 1)
    {
        Show(arr, n);
    }

    for (int i = 0; i < size; i++)
    {
        HeapPermute(arr, n, size - 1);

        if (size % 2 == 1)
            Swap(arr, size, 0);
        else
            Swap(arr, size, i);
    }
}


int main() 
{
    int n;

    printf("Enter N: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    int size = n;

    Fill(arr, size);
    HeapPermute(arr, n, size);
}
