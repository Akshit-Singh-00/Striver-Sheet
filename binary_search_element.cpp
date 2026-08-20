#include<bits/stdc++.h>
using namespace std;

int brute_binary_search(vector<int> arr,int target){
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
    
}//t.c->O(n);s.c->O(1)

int main(){
    vector<int>a={1,2,3,4,5};
    int t=4;
    int result=brute_binary_search(a,t);
    cout<<result<<endl;
    return 0 ;
}