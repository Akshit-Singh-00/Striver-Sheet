#include<bits/stdc++.h>
using namespace std;

int brute_binary_search_element(vector<int> arr,int target){
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
    
}//t.c->O(n);s.c->O(1)

int optimal_binary_search_element(vector<int> arr,int target){
    int n=arr.size();
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
} //t.c->O(logn);s.c->O(1)

int main(){
    vector<int>a={1,2,3,4,5};
    int t=4;
    int result=brute_binary_search_element(a,t);
    cout<<result<<endl;
    int result2=optimal_binary_search_element(a,t);
    cout<<result2;
    return 0 ;
}