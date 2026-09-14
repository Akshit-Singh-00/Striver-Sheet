#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};

class sol{
    public:
int lenght_loop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return countLength(slow);
        }
    }
    return 0;
}
int countLength(Node* pot){
    Node* temp=pot;
    int len=1;
    while (temp->next!=pot)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
};//t.c->O(n);s.c->O(1)

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;


    fifth->next = second;


    sol obj;

    int loopLength = obj.lenght_loop(head);

    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    return 0 ;
}