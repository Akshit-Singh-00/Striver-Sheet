#include<bits/stdc++.h>
using namespace std;

vector<int> brute_shift_zeros(vector<int> arr){

    vector<int> temp(arr.size(),0);
    int index=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            temp[index]=arr[i];
            index++;
        }
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=temp[i];
    }
    return arr;

}// t.c -> O(n) ; s.c -> O(n)

vector<int> optimal_shift_zeros(vector<int> nums){

    int j = -1;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1)
        return nums;

    for(int i = j + 1; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[j], nums[i]);
            j++;
        }
    } // T.c -> O(2n) ; S.c -> O(1)

    return nums;
}

int main(){
    vector<int> vec={0,1,2,3,0,1,0};
    vector<int>result=brute_shift_zeros(vec);
    // cout<<result<<endl; wrong as it is vector
    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;

     vector<int> vec1={1,2,3,1};
    // vector<int>result1=optimal_shift_zeros(vec);
    vector<int>result1=optimal_shift_zeros(vec1);
    
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0 ;
}