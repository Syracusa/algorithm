#include <stdio.h>
#include <string.h>

static void merge(int arr[], int l, int m, int r)
{
    int mergesize = r - l + 1;
    int subarr1_size = m - l + 1;
    int subarr2_size = r - m;

    int subarrbuf[mergesize]; 
    memcpy(subarrbuf, arr + l, mergesize * sizeof(int));

    int *subarr1 = subarrbuf;
    int *subarr2 = subarrbuf + subarr1_size;

    int subarr1_cnt = 0;
    int subarr2_cnt = 0;
    int merged_cnt = l;

    while (subarr1_cnt < subarr1_size && subarr2_cnt < subarr2_size)
    {
        if (subarr1[subarr1_cnt] < subarr2[subarr2_cnt])
            arr[merged_cnt++] = subarr1[subarr1_cnt++];
        else
            arr[merged_cnt++] = subarr2[subarr2_cnt++];
    }

    memcpy(arr + merged_cnt, subarr1 + subarr1_cnt, (subarr1_size - subarr1_cnt) * sizeof(int));
    memcpy(arr + merged_cnt, subarr2 + subarr2_cnt, (subarr2_size - subarr2_cnt) * sizeof(int));
}

static void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

static void mergesort_iterative(int arr[], int l, int r)
{
    int n = r - l + 1;

    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2)
    {
        int merged_size = 2 * curr_size;
        for (int left_start = 0; left_start < n - 1; left_start += merged_size)
        {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;

            if (right_end > n - 1)
                right_end = n - 1;

            merge(arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // mergesort(arr, 0, n - 1);
    mergesort_iterative(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}