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
int Length_loop(Node* head){
    Node* tmp=head;
    map<Node*,int> mp;
    int timer=0;
    while (tmp!=NULL)
    {
        if(mp.find(tmp)!=mp.end()){
            int looplength=timer-mp[tmp];
            return looplength;
        }
         mp[tmp] = timer;
            tmp = tmp->next;
            timer++;
    }
    return 0;
    
}
}; //t.c->O(n);s.c->O(n)

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

    
    int loopLength = obj.Length_loop(head);

  
    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    
    return 0 ;
}