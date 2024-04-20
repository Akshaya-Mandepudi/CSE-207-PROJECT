#include <iostream>
#include <fstream>

using namespace std;

// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n) {
    int isSorted = 0; // Initially array is unsorted

    while (!isSorted) {
        isSorted = 1;

        // Perform Bubble sort on odd indexed element
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
            }
        }

        // Perform Bubble sort on even indexed element
        for (int i = 0; i <= n - 2; i = i + 2) {
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
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }

    int numTestCases;
    inputFile >> numTestCases; // Read the number of test cases from the file

    for (int t = 0; t < numTestCases; t++) {
        int n;
        inputFile >> n; // Read the size of the array for this test case

        int arr[100];
        for (int i = 0; i < n; i++) {
            inputFile >> arr[i]; // Read the elements of the array
        }

        oddEvenSort(arr, n); // Sort the array
        printArray(arr, n); // Print the sorted array
    }

    inputFile.close();
    return 0;
}

