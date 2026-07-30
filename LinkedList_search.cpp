#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class solution{
    public:
    bool LinkedList_search(Node* head,int key){
    Node* temp=head;
    while(temp){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;

    }
};//t.c->O(n);s.c->O(1)

int main(){
    Node* first=new Node(10);
        first->next=new Node(20);
        first->next->next=new Node(30);
        int k;
        cin>>k;
        solution obj;
if (obj.LinkedList_search(first, k))
    cout << "Element Found";
else
    cout << "Element Not Found";
    return 0 ;
}