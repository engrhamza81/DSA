#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Insertion Sort Algorithm
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than current
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current; // Place current in its correct position
    }
    
    // Display sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }

    return 0;
}
