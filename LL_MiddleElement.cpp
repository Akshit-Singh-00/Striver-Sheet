#include <bits/stdc++.h>
using namespace std;

// Optimal - Tortoise and Hare method

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* FindMiddleOne(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
} // t.c->O(n/2);s.c->O(1)

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* middleNode = FindMiddleOne(head);

    cout << "The middle node value is: "
         << middleNode->data << endl;

    return 0;
}