#include <iostream>
using namespace std;
class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapify(int i) {
        int largest = i;
        int l = 2*i +1;
        int r = 2*i +2;

        if (l < size && heap[l] > heap[largest]) {
            largest = l;
        }

        if (r < size && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(int cap){
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full\n";
            return;
        }

        int i = size;
        heap[i] = value;
        size++;
        int parent = (i-1) / 2;

        while (i != 0 && heap[parent] < heap[i]) {
            swap(heap[i], heap[parent]);
            i = parent;
        }
    }

    int getMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        return root;
    }

    void printHeap() {
        for (int i = 0; i <= size; ++i) {
            cout << heap[i] << " ";
        }
        cout <<endl;
    }
};

int main() {
    // MaxHeap maxHeap(10);

    // // Inserting elements into the heap
    // maxHeap.insert(3);
    // maxHeap.insert(9);
    // maxHeap.insert(4);
    // maxHeap.insert(7);
    // maxHeap.insert(5);
    MaxHeap maxHeap(10);
    int num;

    cout << "Enter numbers to insert into the MaxHeap (enter -1 to stop):\n";

    // Read numbers and insert into the heap
    while (true) {
        cin >> num;
        
        // Break the loop if -1 is entered
        if (num == -1) {
            break;
        }

        maxHeap.insert(num);
    }


    cout << "Heap: ";
    maxHeap.printHeap();

    // Print max element
    cout << "Max: " << maxHeap.getMax() << "\n";

    // Extract max element
    cout << "Extracted Max: " << maxHeap.extractMax() << "\n";

    cout << "Heap after extracting max: ";
    maxHeap.printHeap();

    return 0;
}
