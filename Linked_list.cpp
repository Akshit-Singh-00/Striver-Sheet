#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }

}; // t.c->O(1);s.c->O(1)


int main(){
    int a[]={1,2,3,4,5};
    Node* n=new Node(a[0]);

    cout<<n->data<<endl;
    cout<<n->next;
    return 0 ;
}
