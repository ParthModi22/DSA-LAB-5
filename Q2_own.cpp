#include<iostream>
using namespace std;
class heap {
public:
    int arr[100];
    int size;

    heap(){
        size=0;
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
    void increasekey(int index,int val){
        if(index<0 || index>=size){
           cout<<"Invalid Index!"<<endl;
        }
        if(arr[index]>val){
            cout<<"given value if less than the value you want to increase "<<endl;
        }
        else{
            arr[index]=val;
            int parent = (index-1)/2;
            while(index>0 && arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
                parent = (index-1)/2;
            }
        }
    }
    void printheap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
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
    int i,val;
    cout<<"enter index you want to increase "<<endl;
    cin>>i;
    cout<<"enter value for new key "<<endl;
    cin>>val;
    h.increasekey(i,val);

    cout<<"new heap"<<endl;
    h.printheap();

   return 0;
}