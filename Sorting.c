#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        /*Swapping adjacent elements of array such that
        largest element reaches to arr[n-1]*/

        int flag = 0;
        for (int j = 0; j <= n - 1; j++)
        {
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    flag = 1;
                }
            }
            if (flag = 0)
                break;
        }
    }
}

// Quick sort
void quickSort(int arr[], int first, int last)
{

    int i, j, pivot, temp;

    if (first < last)
    {

        pivot = first;

        i = first;

        j = last;

        while (i < j)
        {

            while (arr[i] <= arr[pivot] && i < last)

                i++;

            while (arr[j] > arr[pivot])

                j--;

            if (i < j)
            {

                temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;
            }
        }

        temp = arr[pivot];

        arr[pivot] = arr[j];

        arr[j] = temp;

        quickSort(arr, first, j - 1);

        quickSort(arr, j + 1, last);
    }
}
int main()
{
    int size;
    // inputting the elements of array
    printf("Enter the size of array:\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int choice;
    printf("Sorting algorithms:\n1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Merge Sort\n5.Quick Sort\n");
    printf("Input the sorting algorithm(1/2/3/4/5):\n");
    scanf("%d", &choice);
    // inputting choice of sorting algorithm
    switch (choice)
    {
    case 1:
        insertionSort(arr, size);
        break;

    case 2:
        selectionSort(arr, size);
        break;

    case 3:
        bubbleSort(arr, size);
        break;

    case 4:
        mergeSort(arr, 0, size - 1);
        break;

    case 5:
        quickSort(arr, 0, size - 1);
        break;

    default:
        printf("Invalid choice!");
        break;
    }
    // array is sorted for a valid choice of algorithm
    printf("Array after sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}