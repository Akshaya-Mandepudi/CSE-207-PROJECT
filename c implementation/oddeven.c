#include <stdio.h>

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n) {
    int isSorted = 0; // Initially array is unsorted

    while (!isSorted) {
        isSorted = 1;

        // Perform Bubble sort on odd indexed element
        int i;
        for (i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
            }
        }

        // Perform Bubble sort on even indexed element
        for (i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
            }
        }
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions.
int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
        return 1;
    }

    int arr[100], n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);

    oddEvenSort(arr, n);
    printArray(arr, n);

    return 0;
}
