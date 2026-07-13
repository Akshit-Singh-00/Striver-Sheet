#include<bits/stdc++.h>

using namespace std;

bool brute_sorted(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                return false;
            }
        }
    }
    return true;
} // T.c -> O(n^2) ; S.c -> O(1)

bool optimal_sorted(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<=arr[i-1]){
            return false;
        }
    }
    return true;
}


int main(){
    vector<int> ans1={1,2,3,4,2};
    vector<int> ans2={1,2,3,4,5};
    bool ans=brute_sorted(ans2);

    if(ans){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;;
    }

    bool result=optimal_sorted(ans2);
    if(result){
        cout<<true<<endl;
    }else{
        cout<<false;
    }

    return 0 ;
}