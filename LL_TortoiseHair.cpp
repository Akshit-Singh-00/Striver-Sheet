#include <bits/stdc++.h>
using namespace std;
// Brute Force

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

Node *findMiddle(Node *head)
{
    int cnt = 0;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int mid = cnt / 2 + 1;
    temp = head;
    while (temp != NULL)
    {
        mid--;
        if (mid == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
Node* midone=findMiddle(head);
cout<<"The middle element is :"<<midone<<endl;
cout<<"The middle element is :"<<midone->data<<endl;
    return 0;
}