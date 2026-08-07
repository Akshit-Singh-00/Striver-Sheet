#include<bits/stdc++.h>
using namespace std;

int brute_first_occurence(vector<int> arr,int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cnt++;
        }
    }
    return cnt;
}//t.c->O(n);s.c->O(1)


int first_occurence(vector<int> arr,int target){
    int n=arr.size();
    int l=0;
    int r=n-1;
    int ans1=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==target){
            ans1=mid;
            r=mid-1;
        }
        else if(arr[mid]<target){
            l++;
        }
        else{
            r--;
        }
    }
    return ans1;
    
}

int last_occurence(vector<int> arr,int target){
    int n=arr.size();
    int l=0;
    int r=n-1;
    int ans2=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==target){
            ans2=mid;
            l=mid+1;
        }
        else if(arr[mid]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans2;
    
}

int optimal_occurence(vector<int> arr,int target){
    int first=first_occurence(arr,target);
    if(first==-1){
        return -1;
    }
    int last=last_occurence(arr,target);
    return last-first+1;
}//t.c->O(2*logn);s.c->O(1)

int main(){
    vector<int> a={2, 2 , 3 , 3 , 3 , 3 , 4};
    int x=3;
    int result=brute_first_occurence(a,x);
    cout<<result<<endl;
    
    vector<int> a1={1, 1, 2, 2, 2, 2, 2, 3};
    int x1=2;
    int result2=optimal_occurence(a1,x1);
    cout<<result2<<endl;
    return 0 ;
}