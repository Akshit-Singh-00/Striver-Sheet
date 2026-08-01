#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val,Node* next1,Node* prev1){
        data=val;
        next=next1;
        prev=prev1;
    }
};

Node* ConvertArr2DLL(vector<int> arr){
    if(arr.empty()){
        return nullptr;
    }
    Node* head=new  Node(arr[0],nullptr,nullptr);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
return head;
}

void print(Node* head){
    while (head!=nullptr)   
    {
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}
Node* revDLL(Node* head){
    if(head==nullptr || head->next==nullptr)
    return head;
    stack<int> st;
    Node* temp =head;

    while (temp!=nullptr)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
while (temp!=nullptr)
{
    temp->data=st.top();
    st.pop();
    temp=temp->next;
}
return head;

}//t.c->O(2n) ; s.c->O(n)

class Node2{
public:
    int data;
    Node2* next;
    Node2* prev;

    Node2(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node2* convertDLL(vector<int> arr){

    if(arr.empty()) return nullptr;

    Node2* head = new Node2(arr[0]);
    Node2* prev = head;

    for(int i = 1; i < arr.size(); i++){

        Node2* temp = new Node2(arr[i]);

        prev->next = temp;
        temp->prev = prev;

        prev = temp;
    }

    return head;
}

Node2* ReverseDLL(Node2* head){

    if(head == nullptr || head->next == nullptr)
        return head;

    Node2* curr = head;

    while(curr != nullptr){

        Node2* temp = curr->next;

        curr->next = curr->prev;
        curr->prev = temp;

        head = curr;
        curr = temp;
    }

    return head;
}

void print(Node2* head){

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
} // t.c->O(n);s.c->O(1)


int main(){
      vector<int> arr = {12, 5, 8, 7, 4};

    Node* head = ConvertArr2DLL(arr);//brute force approach

    cout << "Original DLL: ";
    print(head);

    head = revDLL(head);

    cout << "Reversed DLL: ";
    print(head);
cout<<endl;


Node2* head2=convertDLL(arr);//Optimal approcah;
head2=ReverseDLL(head2);
cout << "Original DLL: ";
Node2* original = convertDLL(arr);
print(original);

head2 = ReverseDLL(original);
cout<<endl;
cout << "Reversed DLL: ";
print(head2);
    return 0 ;
}