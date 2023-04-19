#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void Fill(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 20;
    }
}

void Swap(int* num1, int* num2) 
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void MaxHeap(int arr[], int size, int i) 
{
    int parent = i;
    int child_left = 2 * i + 1;
    int child_right = 2 * i + 2;

    if (child_left < size && arr[child_left] > arr[parent])
        parent = child_left;

    if (child_right < size && arr[child_right] > arr[parent])
        parent = child_right;

    if (parent != i) 
    {
        Swap(&arr[i], &arr[parent]);
        MaxHeap(arr, size, parent);
    }
}

void Sort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        MaxHeap(arr, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        MaxHeap(arr, i, 0);
    }
}

void Show(int arr[], int size) 
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    srand(time(NULL));

    int arr[SIZE];

    Fill(arr, SIZE);
    Sort(arr, SIZE);

    printf("Sorted array: \n");
    Show(arr, SIZE);
}
