#include<bits/stdc++.h>
using namespace std;

int binary_lower_bound_1st(vector<int> arr,int x){
int n=arr.size();
for(int i=0;i<n;i++){
    if(arr[i]>x){
        return arr[i];
    }
}
return n;
}//t.c->O(n);s.c->O(1)

int binary_lower_bound_2nd(vector<int> arr,int x){
    int n=arr.size();
    int left=0;
    int right=n-1;
    int ans;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]>x){
            ans=arr[mid];
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}//t.c->O(nlogn);s.c->O(1)

int main(){
    vector<int> a={1,2,3,5};
    vector<int> a1={3,5,8,15,19};
    int x=3;
    int x1=9;
    int reuslt1=binary_lower_bound_1st(a,x);
    cout<<reuslt1<<endl;
    int reuslt11=binary_lower_bound_2nd(a1,x1);
    cout<<reuslt11<<endl;

    
    return 0 ;
}