#include<bits/stdc++.h>
using namespace std;

int brute_majority_element(vector<int> arr){

 for(int i=0;i<arr.size();i++){
    int count=0;
    for(int j=0;j<arr.size();j++){
        if(arr[i]==arr[j]){
            count++;
        }
    }
    if(count>arr.size()/2){
        return arr[i];
    }
 }
return -1;
} // t.c->O(n^2);s.c->O(1)

int better_majority_element(vector<int> arr){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[i]++;
    }
    for(auto it:mp){
        if(it.second>arr.size()/2){
            return it.first;
        }
    }
    return -1;
}//t.c->O(n) ;s.c->O(n)

//Moore's Voting Algorithm.
int optimal_majority_element(vector<int> arr){
    int count=0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            count++;
            el=arr[i];
        }
        else if(el==arr[i]){
            count++;
        }
        else {
            count--;
        }
    }
     int count1=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==el){
                count1++;
            }
        }
        if(count1>arr.size()/2){
            return el;
        }
        return -1;
}//t.c->O(n) ;s.c->O(1)

int main(){
    
    vector<int> ans={3,2,3,3,2,3,4,3};
int result1=brute_majority_element(ans);
cout<<result1<<endl;
vector<int> ans1={3,2,3,3,2,4};
int result2=better_majority_element(ans1);
cout<<result2<<endl;
int result13=optimal_majority_element(ans);
cout<<result13<<endl;
int result4=optimal_majority_element(ans1);
cout<<result4;
    return 0 ;
}