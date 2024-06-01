#include <iostream>
#include <vector>
using namespace std;

struct heapnode{
    int value;
    int listindex;
    int elementindex;
};
void minheapify(vector <heapnode> &heap, int i,int s){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<s && heap[left].value<heap[smallest].value)
    smallest=left;
    if(right<s && heap[right].value<heap[smallest].value)
    smallest=right;
    if(smallest!=i)
    {swap(heap[i],heap[smallest]);
    minheapify(heap,smallest,heap.size());}
    }
void buildminheap(vector <heapnode> &heap){ 
    int n=heap.size();
    for(int i=n/2-1;i>=0;i--)
    minheapify(heap,i,heap.size());
}
heapnode extractmin(vector <heapnode> &heap){
    heapnode min=heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    if(!heap.empty())
    minheapify(heap,0,heap.size());
    return min;
}
void insertheap(vector <heapnode> &heap, heapnode node){
    heap.push_back(node);
    int i=heap.size()-1;
    while(i>0 && heap[(i-1)/2].value>heap[i].value){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2; // moving to parent node
    }
}
vector <int> sortedlist(vector <vector <int>> &lists){
    vector <heapnode> minheap;
    vector <int> result;
    for(int i=0;i<lists.size();i++){
        if(!lists[i].empty())
        minheap.push_back({lists[i][0],i,0});
    }
    buildminheap(minheap);
    while(!minheap.empty()){
        heapnode root=extractmin(minheap);
        result.push_back(root.value);
        if(root.elementindex+1<lists[root.listindex].size()) //next element < list size 
        insertheap(minheap,{lists[root.listindex][root.elementindex+1],root.listindex,root.elementindex+1}); 
                              // {next element,list no.,element no.}
    }
    return result;
}
int main(){
    vector <vector <int> > lists={{1,4,5},{1,3,4},{2,6}};
    vector <int> result=sortedlist(lists);
    for(int h : result)
    cout<<h<<" ";
}