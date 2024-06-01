#include<iostream>
#include<queue>
using namespace std;
// class with constructor for a node of Linked list
class Node {
    public:
    int data;
    Node* next;
    // constructor
    Node(int x){
        data = x;
        next = NULL;
    }
};
// This function prints data of the linked list
void print(Node* head)
{
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout<<"NULL";
}
// comparator function for the priority queue to
// make it behave as a min-heap
struct compare
{
    bool operator()(Node* &a,Node* &b)
    {
        return a->data > b->data;
    }
};
// merges 'K' sorted lists into one sorted list
Node* mergeKLists(Node* arr[], int back)
{
    priority_queue<Node*,vector<Node*>,compare>minh;
    for(int i=0;i<=back;i++)
    {
        if(arr[i]!=NULL) minh.push(arr[i]);
    }
    Node* head=new Node(0);
    Node* temp=head;
    while(minh.size()>0)
    {
        Node* p = minh.top();
        minh.pop();
        temp->next = p;
        temp=temp->next;
        if(p->next!=NULL) minh.push(p->next);
    }
    return head->next;
}
int main()
{
    Node * arr[3];
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    Node *h2 = new Node(1);
    h2->next = new Node(4);
    h2->next->next = new Node(8);
    Node *h3 = new Node(6);
    h3->next = new Node(7);
    h3->next->next = new Node(9);
    arr[0] = head;
    arr[1] = h2;
    arr[2] = h3;
    
    cout<<"Final resultant merged linked list"<<endl;
    print(mergeKLists(arr,2));
    
   return 0;
}