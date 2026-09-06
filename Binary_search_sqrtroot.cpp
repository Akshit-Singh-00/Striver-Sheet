#include<bits/stdc++.h>
using namespace std;

int brute_square_root(int n){
    int ans=0;
    for(int i=1;i<n;i++){
        if(i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}//t.c->O(n);s.c->O(1)

int optimal_square_root(int n){
    int left=0;
    int right=n-1;
    int ans=0;
     while (left<=right)
     {
        int mid=(left+right)/2;
        if(mid*mid<=n){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
     }
     return ans;
     
}//t.c->O(logn);s.c->O(1)

int main(){
     int n = 27;
     cout<<brute_square_root(n)<<endl;
     cout<<optimal_square_root(n)<<endl;
    return 0 ;
}