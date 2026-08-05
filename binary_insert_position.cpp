#include<bits/stdc++.h>
using namespace std;


int binary_insert_position(vector<int> arr,int x){
    int n=arr.size();
    int left=0;
    int right=n-1;
    int ans=n;
    while (left<=right) 
    {
        int mid=(left+right)/2;
        if(arr[mid]>=x){
ans=mid;
right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
    
}//t.c->O(nlogn);s.c->O(1)

int main(){
    vector<int> arr={1, 2, 4, 7};
    int x=6;
    int result=binary_insert_position(arr,x);
    cout<<result;

    return 0 ;
}