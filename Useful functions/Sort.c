#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                swap = 1;
            }
        }

        if (swap == 0) {
            break;
        }
    }
}

void merge(int x[], int l, int m, int r) {
    int len_l = m - l + 1;
    int len_r = r - m;

    int xl[len_l];
    int xr[len_r];

    for (int i = 0; i < len_l; i++) {
        xl[i] = x[l + i];
    }

    for (int i = 0; i < len_r; i++) {
        xr[i] = x[m + i + 1];
    }

    int a = 0;
    int b = 0;

    for (int i = l; i <= r; i++) {
        if (a <= len_l && b <= len_r) {
            if (xl[a] < xr[b]) {
                x[i] = xl[a++];
            } else {
                x[i] = xr[b++];
            }

        } else {
            if (a > len_l) {
                x[i] = xr[b++];
            } else {
                x[i] = xl[a++];
            }
        }
    }
}

void merge_sort(int x[], int l, int r) {
    if (l == r) {
        return;
    }

    int m = (l + r) / 2;

    merge_sort(x, l, m);
    merge_sort(x, m + 1, r);
    merge(x, l, m, r);
}

void qs(int arr[], int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = arr[(left + right) / 2];

        while (left < right) {
            while (arr[left] < middle) {
                left++;
            }

            while (arr[right] > middle) {
                right--;
            }

            if (left <= right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }

        qs(arr, first, right);
        qs(arr, left, last);
    }
}

int bin_search(int x[], int n, int elem) {
    int left = 0;
    int right = n - 1;

    if (x[left] == elem) {
        return left;
    }

    if (x[right] == elem) {
        return right;
    }

    while (left <= right) {
        int m = (left + right) / 2;

        if (x[m] == elem) {
            return m;
        }

        if (x[m] > elem) {
            right = m - 1;
        } else {
            left = m + 1;
        }
    }

    return -1;
}