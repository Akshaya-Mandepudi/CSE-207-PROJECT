#include <iostream>
#include <fstream> // For file operations
#include <cstdlib> // For exit()

using namespace std;

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n) {
    bool isSorted = false; // Initially array is unsorted

    while (!isSorted) {
        isSorted = true;

        // Perform Bubble sort on odd indexed element
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        // Perform Bubble sort on even indexed element
        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program to test above functions.
int main() {
    ifstream inputFile("input.txt"); // Open input file
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file!" << endl;
        exit(EXIT_FAILURE); // Exit the program with an error code
    }

    int arr[100], n = 0;
    while (n < 100 && inputFile >> arr[n]) { // Read integers from input file
        n++;
    }
    inputFile.close(); // Close input file

    cout << "Sorted array: ";
    oddEvenSort(arr, n);
    printArray(arr, n);

    return 0;
}
