#include <bits/stdc++.h>
using namespace std;

//Optimal 
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Sol {
public:
    Node* head;

    Sol() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void print() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    void sortZeroOneTwo() {

        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);

        Node* zero = zeroDummy;
        Node* one = oneDummy;
        Node* two = twoDummy;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        zero->next = oneDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;

        head = zeroDummy->next;

        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;
    }
}; // t.c->O(n);s.c->O(1)

int main() {

    Sol obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(0);
    obj.insert(1);
    obj.insert(2);
    obj.insert(0);

    cout << "Original List: ";
    obj.print();

    obj.sortZeroOneTwo();

    cout << "Sorted List: ";
    obj.print();

    return 0;
}