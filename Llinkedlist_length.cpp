#include<bits/stdc++.h>
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
    int length_linkedist(Node* head){
int count=0;
Node* temp=head;
while(temp){
    count++;
    temp=temp->next;
}
return count;
    }
}; // t.c->O(n);s.c->O(1)

int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    solution obj;
    cout<<"The length of linkedlist is - "<<obj.length_linkedist(head);
    return 0 ;
}