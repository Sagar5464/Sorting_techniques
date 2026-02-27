#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves
void Merge(int a[], int low, int mid, int high){
    int left = low;        // starting index of left half
    int right = mid + 1;   // starting index of right half
    vector<int> temp;      // temporary array
    // Compare elements from both halves
    while (left <= mid && right <= high){
        if (a[left] < a[right])
            temp.push_back(a[left++]);
        else
            temp.push_back(a[right++]);
    }
    // Copy remaining elements from left half
    while (left <= mid)
        temp.push_back(a[left++]);

    // Copy remaining elements from right half
    while (right <= high)
        temp.push_back(a[right++]);

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
        a[i] = temp[i - low];
}

// Recursive Merge Sort function
void MergeSort(int a[], int low, int high){
    // Base condition: single element
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    
    MergeSort(a, low, mid);     // Sort left half
    
    MergeSort(a, mid + 1, high);    // Sort right half
    
    Merge(a, low, mid, high);    // Merge both halves
}

int main(){
    int n;
    cin >> n;   
    int a[n];   
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
