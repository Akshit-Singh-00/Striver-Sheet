#include <bits/stdc++.h>
using namespace std;

//Optimal Approach

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Sol
{
public:
    Node *print(Node *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
        Node *delNthnode(Node * head, int n)
        {
            Node *dummy=new Node(0);
            dummy->next=head;

            Node *slow=dummy;
            Node *fast=dummy;
            for(int i=0;i<n;i++){
                fast=fast->next;
            }
            while (fast!=NULL)  
            {
                slow=slow->next;
                fast=fast->next;
            }
            slow->next=slow->next->next;
            return dummy->next;
        }
    
};//T.c->O(n);s.c->O(1)

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

 
    Sol obj;

    
    head = obj.delNthnode(head, N);

 
    obj.print(head);

    return 0;
}