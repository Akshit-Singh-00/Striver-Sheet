#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class solution {
public:

    Node* add_two_number(Node* l1, Node* l2) {

        // Dummy node
        Node* dumy = new Node(0);
        Node* temp = dumy;

        int c = 0;

        while (l1 != NULL || l2 != NULL || c) {

            // Start with carry
            int sum = c;

            if (l1 != NULL) {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->data;
                l2 = l2->next;
            }

            // Calculate carry
            c = sum / 10;

            // Create result node
            Node* newNode = new Node(sum % 10);

            // Attach it to result list
            temp->next = newNode;

            // Move temp
            temp = temp->next;
        }

        return dumy->next;
    }
};

Node* createList(vector<int> arr) {

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

void print(Node* head) {

    while (head) {
        cout << head->data;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
} // t.c->O(max(m,n)) ; s.c->O(max(m,n))

int main() {

    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6};

    Node* l1 = createList(num1);
    Node* l2 = createList(num2);

    solution obj;

    Node* result = obj.add_two_number(l1, l2);

    print(result);

    return 0;
}