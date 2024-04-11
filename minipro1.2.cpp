#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[minIndex], &arr[i]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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

void merge(int arr[], int l, int m, int r) {
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

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));

    int n = 10000; // Adjust the size of the array as needed
    int arr[n], arrCopy[n];

    // Generate a random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
        arrCopy[i] = arr[i];
    }

    clock_t start, end;

    // Bubble Sort
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    printf("Bubble Sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Selection Sort
    for (int i = 0; i < n; i++)
        arr[i] = arrCopy[i]; // Reset array to unsorted state

    start = clock();
    selectionSort(arr, n);
    end = clock();
    printf("Selection Sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Quick Sort
    for (int i = 0; i < n; i++)
        arr[i] = arrCopy[i]; // Reset array to unsorted state

    start = clock();
    quickSort(arr, 0, n-1);
    end = clock();
    printf("Quick Sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Insertion Sort
    for (int i = 0; i < n; i++)
        arr[i] = arrCopy[i]; // Reset array to unsorted state

    start = clock();
    insertionSort(arr, n);
    end = clock();
    printf("Insertion Sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Merge Sort
    for (int i = 0; i < n; i++)
        arr[i] = arrCopy[i]; // Reset array to unsorted state

    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();
    printf("Merge Sort: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}
