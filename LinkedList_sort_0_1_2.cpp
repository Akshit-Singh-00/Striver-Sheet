#include <bits/stdc++.h>
using namespace std;

 // BRUTE FORCE 
class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};


class Sol {
public:
    Node* Sort(Node* head) {

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

       
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->val == 0)
                cnt0++;
            else if (temp->val == 1)
                cnt1++;
            else
                cnt2++;

            temp = temp->next;
        }

    
        temp = head;

        while (temp != nullptr) {

            if (cnt0 > 0) {
                temp->val = 0;
                cnt0--;
            }
            else if (cnt1 > 0) {
                temp->val = 1;
                cnt1--;
            }
            else {
                temp->val = 2;
                cnt2--;
            }

            temp = temp->next;
        }

        return head;
    }
}; // t.c->O(2n) ; s.c->O(1)

int main() {

   
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

  
    Sol obj;
    head = obj.Sort(head);

 
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}