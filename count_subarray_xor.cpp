#include<bits/stdc++.h>
using namespace std;

int brute_count__subarray_xor(vector<int> arr,int s){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int xorr=0;
        
        for(int j=i;j<arr.size();j++){
            xorr=xorr^arr[j];
            if(xorr==s){
            count++;
            }
        }
    }
    return count;
}//t.c->O(n^2);s.c->O(1)

int optimal_count_subarray_xor(vector<int> arr,int k){
    unordered_map<int,int> mp;
    mp[0]=1;
    int prefixXor=0;
    int count=0;
    for(auto it :arr){
        prefixXor^=it;
        int target=prefixXor^k;
        if(mp.find(target)!=mp.end()){
            count+=mp[target];
        }
        mp[prefixXor]++;
    }
    return count;
}//t.c->O(n);s.c->O(n)

int main(){
     vector<int> arr={4, 2, 2, 6, 4};
     int s ;
     cin>>s;
     int result=brute_count__subarray_xor(arr,s);
     cout<<result<<endl;
     int result1=brute_count__subarray_xor(arr,s);
     cout<<result1<<endl;
    return 0 ;
}