#include <iostream>
using namespace std;
// Max-Heapify function to maintain heap property
void maxHeapify(int arr[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, heapSize, largest);
    }
}

// Build Max-Heap
void buildMaxHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

// Heapsort function
void heapSort(int arr[], int size) {
    // Build Max-Heap
    buildMaxHeap(arr, size);

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Main function to test Heapsort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, size);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
