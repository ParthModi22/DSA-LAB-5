#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap(){
        size=0;
    }
    void maxheapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxheapify(largest);
        }
    }

    void printmax() {
        cout << arr[0] << endl;
    }

    void extractmax() {
        swap(arr[0], arr[size - 1]);
        size--;
        maxheapify(0);
    }

    void insert(int value) {
        size++;
        int index = size - 1;
        arr[index] = value;
        int parent = (index - 1) / 2;
        while (index > 0 && arr[parent] < arr[index]) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void printheap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    int num;
    
    cout<<"enter numbers to insert in heap(-1 to stop) "<<endl;
    while(true){
        cin>>num;

        if(num ==-1){
            break;
        }
        h.insert(num);
        cout<<"insertion of "<<num<<" successfull in heap "<<endl;
    }
    cout<<"Initial heap: ";
    h.printheap();
    cout<<endl;
    cout<<"using print max: ";
    h.printmax();
    cout<<endl;
    cout<<"using extract max: "<<endl;
    h.extractmax();
    cout<<endl;
    cout<<"heap after extracting max: ";
    h.printheap();
    return 0;
}
