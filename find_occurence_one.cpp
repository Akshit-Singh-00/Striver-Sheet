#include<bits/stdc++.h>
using namespace std;

int brute_occurence_one(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        int count=0;
        int num=arr[i];
    
    for(int j=0;j<arr.size();j++){
        if(arr[j]==num){
            count++;
        }
    }
    if(count==1) return arr[i]; // or return i for index
    }
    return -1;
} // T.c->O(n^2) ; S.c->o(1)

int better_occurence_one(vector<int> arr){
    int maxi=arr[0];
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }
    vector<int> hash(maxi+1,0);
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(hash[arr[i]]==1){
            return arr[i];
        }
    }
    return -1;

} // T.c -> O(3n) ; s.c-> O(n)

int optimal_occurence_one(vector<int> arr){
    int xorr=0;
    for(int i=0;i<arr.size();i++){
  xorr=xorr^arr[i];
    }
    return xorr;
} // T.c->O(n) ; S.c->O(1)

int main(){
    vector<int> vec={1,1,2,2,3};
    vector<int> vec1={1,1,2,2,3,3};
 cout<<brute_occurence_one(vec)<<endl;
 cout<<better_occurence_one(vec)<<endl;
 cout<<optimal_occurence_one(vec)<<endl;
    return 0 ;
}