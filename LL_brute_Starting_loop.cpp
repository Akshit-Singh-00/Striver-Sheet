#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};
class Sol
{
public:
    Node *findstarting_loop(Node *head)
    {
        Node* temp=head;
        unordered_set<Node*> st;
        while (temp!=NULL)
        {
            if(st.find(temp)!=st.end()){
                return temp;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};//t.c->O(n);s.c->O(n)

int main()
{
     Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    
    head->next->next->next->next = head->next;

    Sol obj;
    Node* startNode = obj.findstarting_loop(head);

    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}