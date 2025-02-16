#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    bool swapped; // Flag to check if a swap occurred

    for (int i = 0; i < size - 1; i++) {
        swapped = false; // Reset the swap flag for this pass

        // Perform a pass through the array
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true; // A swap occurred
            }
        }

        // If no swaps were made, the array is sorted
        if (!swapped) {
            break; // Exit the loop early
        }
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, size); // Sort the array

    cout << "Sorted Array: ";
    displayArray(arr, size); // Display the sorted array

    return 0;
}
