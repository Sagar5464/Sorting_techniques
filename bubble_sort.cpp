#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // Swap if elements are in wrong order
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];   // dynamic array

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;  // free memory
    return 0;
}
