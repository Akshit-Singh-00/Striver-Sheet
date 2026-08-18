#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insert(Node*& head, Node*& tail, int value) {

    Node* newNode = new Node(value);

    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* head) {

    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

Node* segregate(Node* head) {

    Node* evenHead = NULL;
    Node* evenTail = NULL;

    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data % 2 == 0) {
            insert(evenHead, evenTail, temp->data);
        }
        else {
            insert(oddHead, oddTail, temp->data);
        }

        temp = temp->next;
    }


    if (evenHead == NULL)
        return oddHead;


    evenTail->next = oddHead;

    return evenHead;
} //t.c->O(n); s.c->O(1)

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);

    cout << "Original List:" << endl;
    print(head);

    head = segregate(head);

    cout << "After Segregation:" << endl;
    print(head);

    return 0;
}