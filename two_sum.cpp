#include<bits/stdc++.h>
using namespace std;

vector<int> brute_two_sum(vector<int> arr,int target){
       for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
       }
       return {-1,-1};
} // T.c-> O(n^2) ; S.c->O(1)

vector<int> better_two_sum(vector<int> arr,int target){
  unordered_map<int,int> mp;
  for(int i=0;i<arr.size();i++){
    int temp=target-arr[i];
    if(mp.find(temp)!=mp.end()){
        return {mp[temp],i};
    }
    mp[arr[i]]=i;
  }
  return {-1,-1};
} // T.c-> O(n) ; S.c->O(n)



int main(){
    
    vector<int> vec={1,2,3,4,5};
    int t=4;
    vector<int> result=brute_two_sum(vec,t);
    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result1=better_two_sum(vec,t);
    for(auto it:result1){
        cout<<it<<" ";
    }
    return 0 ;
}