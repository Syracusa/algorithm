#include <stdio.h>
#include <string.h>

static void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = arr[r];
        int i = l;

        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;

        quicksort(arr, l, i - 1);
        quicksort(arr, i + 1, r);
    }
}

static void quicksort_iterative(int arr[], int l, int r)
{
    int stack[r - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = r;

    while (top >= 0)
    {
        r = stack[top--];
        l = stack[top--];

        int pivot = arr[r];
        int i = l;

        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;

        if (i - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = i;
        }

        if (i + 1 < r)
        {
            stack[++top] = i + 1;
            stack[++top] = r;
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // quicksort(arr, 0, n - 1);
    quicksort_iterative(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}