#include<bits/stdc++.h>
using namespace std;

void  brute_largest(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    cout<<arr[n-1]<<endl;
} // T.c -> O(nlogn) ; S.c -> O(1)

void optimal_largest(vector<int> arr){
    int first=arr[0];
    for(int i=0;i<arr.size();i++){
       if(first<arr[i]){
        first=arr[i];
       }
    }
    cout<<first<<endl;
}

int main(){
    vector<int> ans={3,21,4,5,3};
    vector<int> ans1={3,21,4,5,3,65};
    int size=ans.size();
    brute_largest(ans,size);
    optimal_largest(ans1);
    return 0 ;
}