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

int main(){
      vector<int> arr = {12, 5, 8, 7, 4};

    Node* head = ConvertArr2DLL(arr);

    cout << "Original DLL: ";
    print(head);

    head = revDLL(head);

    cout << "Reversed DLL: ";
    print(head);

    return 0 ;
}