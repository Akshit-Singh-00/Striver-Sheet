#include<bits/stdc++.h>
using namespace std;

int brute_minimum_search(vector<int> arr){
    int n=arr.size();
    int min_num=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        min_num=min(min_num,arr[i]);
    }
    return min_num;
    
}//t.c->O(n);s.c->O(1)


int optimal__minimum_search(vector<int> arr){
    int n=arr.size();
    int l=0;
    int r=n-1;
    int ans=INT_MAX;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[l]<=arr[mid]){
            ans=min(ans,arr[l]);
            l=mid+1;
        }
        else{
            r=mid-1;
            ans=min(ans,arr[mid]);
        }
    }
    return ans;
    
}//t.c->O(logn) ; s.c->O(1)

int main(){
    vector<int> arr={4,5,6,7,0,1,2,3};
    int result=brute_minimum_search(arr);
    cout<<result<<endl;
    int result1=optimal__minimum_search(arr);
    cout<<result1;
    return 0 ;
}