#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)  // Fixed increment operator
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)  // Fixed increment operator
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;  // Fixed increment operator
        } else {
            arr[k] = R[j];
            j++;  // Fixed increment operator
        }
        k++;  // Fixed increment operator
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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements (n > 5000): ");
    scanf("%d", &n);

    if (n < 5000) {
        printf("Please enter a value greater than 5000.\n");
        return 1;
    }

    int arr[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);
    printf("Sorted elements (First 10):\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


// Enter the number of elements (n > 5000): 9000
// Time taken to sort 9000 elements: 0.001732 seconds
// Sorted elements (First 10):
// 0 0 1 1 2 6 6 7 7 8 