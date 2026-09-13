#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

class sol {
public:
    bool findloop(Node* head) {
        map<Node*, int> mp;
        Node* temp = head;

        while (temp != nullptr) {
            if (mp.find(temp) != mp.end())
                return true;

            mp[temp] = 1;
            temp = temp->next;   
        }

        return false;
    }
}; // t.c->O(n*logn);s.c->O(n)

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    sol obj;

    if (obj.findloop(head))
        cout << "Loop detected";
    else
        cout << "No loop detected";

    return 0;
}