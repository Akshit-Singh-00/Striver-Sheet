#include<bits/stdc++.h>
using namespace std;

int brute_count_subarray_sum_0(vector<int> arr,int kk){
    int count=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==kk){
                maxi=max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}//t.c->O(n^3);s.c->O(1)

int better_count_subarray_sum_0(vector<int> arr,int kk){
    int maxi=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum=sum+arr[j];
            if(sum==kk){
                maxi=max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}//t.c->O(n^2);s.c->O(1)


int optimal_count_subarray_sum_0(vector<int> arr){
    unordered_map<int,int> mp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
    }
    return maxi;
}//t.c->O(n);s.c->O(n)

int main(){
vector<int> arr={9, -3, 3, -1, 6, -5};
vector<int> arr1={6, -2, 2, -8, 1, 7, 4, -10} ;
int k=0;
int result=brute_count_subarray_sum_0(arr,k);
cout<<result<<endl;
int result1=better_count_subarray_sum_0(arr1,k);
cout<<result1<<endl;
int result12=optimal_count_subarray_sum_0(arr1);
cout<<result12<<endl;
    return 0 ;
}