#include<bits/stdc++.h>
using namespace std;

int  brute_binary_last_occurence(vector<int> arr,int x){
    int n=arr.size();
    for(int i=n-1;i>0;i--){
        if(arr[i]==x){
            return i;
            break;
        }
    }
    return n;
}//t.c-O(n);s.c->O(1)


int optimal_binary_last_occurence(vector<int> arr,int x){
    int n=arr.size();
    int left=0;
    int right=n-1;
    int ans=-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==x){
            ans=mid;
            left=mid+1;
        }
        else if(x<arr[mid]){
            right--;
        }
        else{
            left++;
        }
    }
    return ans;
    
}//t.c->O(logn) ;s.c->O(1)

int main(){
    vector<int> arr={3, 4, 13, 13, 13, 20, 40} ;
    int x=13;
    int result1=brute_binary_last_occurence(arr,x);
    cout<<result1<<endl;

    int result12=optimal_binary_last_occurence(arr,x);
    cout<<result12;
    return 0 ;
}