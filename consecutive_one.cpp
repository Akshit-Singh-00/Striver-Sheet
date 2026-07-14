#include<bits/stdc++.h>
using namespace std;

int consecuitve_one(vector<int> nums){
    int count=0;
    int max_count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count+=1;
        }
        else{
            count=0;
        }
        max_count=max(max_count,count);
    }
    return max_count;
} // T.c -> O(n) ; S.c -> O(1)

int main(){
    
  vector<int> arr={1,2,3,0,0,1,1,0};
  int result=consecuitve_one(arr);
  cout<<result;
    return 0 ;
}