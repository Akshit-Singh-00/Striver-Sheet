#include<bits/stdc++.h>
using namespace std;

int brute_binary_upper_bound(vector<int> arr,int x){
    int n=arr.size();
for(int i=0;i<n;i++){
    if(arr[i]>x){
        return arr[i];
    }
}
return n;
}//t.c->O(n);s.c->O(1)

int optimal_binary_upper_bound(vector<int> arr,int x){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            return arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return n;
}//t.c->O(nlogn);s.c->O(1)

int main(){
     vector<int> arr = {3, 5, 8, 9, 15, 19};
      int x = 9; 
      int result1=brute_binary_upper_bound(arr,x);
      cout<<result1<<endl;

      int result12=optimal_binary_upper_bound(arr,x);
      cout<<result12;

    return 0 ;
}