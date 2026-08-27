#include <bits/stdc++.h>
using namespace std;

// Brute force
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

class sol
{
public:
    void print(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout <<" "<< temp->data;
            temp = temp->next;
        }
        cout<<endl;
    }
    bool check_pallindrome(Node *head){
        stack<int> st;

        Node *temp=head;
        while (temp!=NULL)
        {
            st.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while (temp)
        {
            if(temp->data!=st.top()){
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
        
        
    }
}; // t.c->O(n);s.c->O(n)

int main()
{
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);
    cout<<"Original Linked List";
    sol obj;
    obj.print(head);
    if(obj.check_pallindrome(head)){
        cout<<"The linked list is palindrome"<<endl;
    }
    else{
        cout<<"The linked list is not palindrome"<<endl;
    }
    return 0;
}