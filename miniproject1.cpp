#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 1000

// Bubble Sort Algorithm
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort Algorithm
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Algorithm
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Algorithm
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
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

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort Algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements (up to 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ELEMENTS) {
        printf("Invalid input. Please enter a number between 1 and 1000.\n");
        return 1; // Exit with error status
    }

    if (n > 1000) {
        printf("Note: The number of elements is greater than 1000. This may affect the performance of the sorting algorithms.\n");
    }

    int arr[n];

    // Generating random integers within the range of 0 to 100
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Measure execution time for Bubble Sort
    clock_t start_bubble = clock();
    bubble_sort(arr, n);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort: %.6f seconds\n", time_bubble);

    // Measure execution time for Selection Sort
    clock_t start_selection = clock();
    selection_sort(arr, n);
    clock_t end_selection = clock();
    double time_selection = ((double) (end_selection - start_selection)) / CLOCKS_PER_SEC;
    printf("Time taken by Selection Sort: %.6f seconds\n", time_selection);

    // Measure execution time for Insertion Sort
    clock_t start_insertion = clock();
    insertion_sort(arr, n);
    clock_t end_insertion = clock();
    double time_insertion = ((double) (end_insertion - start_insertion)) / CLOCKS_PER_SEC;
    printf("Time taken by Insertion Sort: %.6f seconds\n", time_insertion);

    // Measure execution time for Merge Sort
    clock_t start_merge = clock();
    merge_sort(arr, 0, n - 1);
    clock_t end_merge = clock();
    double time_merge = ((double) (end_merge - start_merge)) / CLOCKS_PER_SEC;
    printf("Time taken by Merge Sort: %.6f seconds\n", time_merge);

    // Measure execution time for Quick Sort
    clock_t start_quick = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end_quick = clock();
    double time_quick = ((double) (end_quick - start_quick)) / CLOCKS_PER_SEC;
    printf("Time taken by Quick Sort: %.6f seconds\n", time_quick);

    return 0;
}
