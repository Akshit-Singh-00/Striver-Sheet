#include<bits/stdc++.h>
using namespace std;

void brute_left_rotate_one_place(vector<int> arr){
    int n=arr.size();
    vector<int> temp(n);
    for(int i=1;i<n;i++){
          temp[i-1]=arr[i];
    }

    temp[n-1]=arr[0];
    for(auto it:temp){
        cout<<it<<" ";
    }
} // T.c-> O(n) ; S.c - O(n)

void optimal_left_rotate_one_place(vector<int> arr){

int n=arr.size();
    int temp=arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    for(auto it:arr){
        cout<<it;
    }
} // T.c->O(n) ; s.c->O(1)

int main(){
    vector<int> vec={1,2,3,4,5};
    brute_left_rotate_one_place(vec);
    optimal_left_rotate_one_place(vec);
    return 0 ;
}