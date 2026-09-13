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

class Sol{
    public:
    Node* find_starting_head(Node* head){
        Node* slow=head;
        Node* fast=head;

        if(fast!=NULL || fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
            }
            while (slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
return slow;
            }
            
        }
        return NULL;
    }
};//t.c->O(n);s.c->O(1)

int main(){
     Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

   
    head->next->next->next->next = head->next;

    Sol obj;
    Node* result = obj.find_starting_head(head);

    if (result != NULL)
        cout << "Cycle starts at node with value: " << result->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0 ;
}