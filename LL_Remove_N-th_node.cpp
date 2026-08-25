#include <bits/stdc++.h>
using namespace std;
// brute force
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
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
        Node *deleteNthnode(Node * head, int n)
        {
            int cnt = 0;
            Node* temp=head;
            if (head == NULL)
            {
                return NULL;
            }
              while (temp!=NULL)
              {
                cnt++;
                temp=temp->next;
              }
              if(cnt==n){
                Node* newhead=head->next;
                delete newhead;
                return newhead;
              }
              int res=cnt-n;
              temp=head;
              while (temp)
              {
                res--;
                if(res==0){
                    break;
                }
                temp=temp->next;
              }
              Node* delNode=temp->next;
              temp->next=temp->next->next;
              delete delNode;
              return head;
              
        }
    
}; // T.c->O((L)+O(L-N)) ; S.c->O(1)

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
    head = obj.deleteNthnode(head, N);
    obj.print(head);
    return 0;
}