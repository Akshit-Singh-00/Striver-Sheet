#include<bits/stdc++.h>
using namespace std;

bool linear_serach(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            return arr[i];
        }
    }
    return false;
    
}

int main(){
    int arr[]={1,2,3,4,5,6
    };
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
bool result=linear_serach(arr,n,key);
if(result){
    cout<<true;
}
else{
    cout<<false;
}
    
    return 0 ;
}