#include<bits/stdc++.h>
using namespace std;

int brute_max_product_subarray(vector<int> arr){
    int maxProduct=0;
    for(int i=0;i<arr.size();i++){
        int product=1;
        for(int j=0;j<arr.size();j++){
            product*=arr[j];
            maxProduct=max(maxProduct,product);
        }
    }
    return maxProduct;
}//t.c->O(n^2);s.c->O(1)

int optimal_max_product_subarray(vector<int> arr){
    int ans=0;
    int n=arr.size();
    int pre=0,suf=0;
    for(int i=0;i<n;i++){
        if(suf==0)suf=1;
        if(pre==0)pre=1;
        pre*=arr[i];
        suf*=arr[n-i-1];
        ans=max(ans,max(pre,suf));
    }
    return ans;
}//t.c->O(n);s.c->O(1) 

int main(){
    vector<int> arr={1,2,3,4,5,0};
    vector<int> arr1={1,2,-3,0,-4,-5};
    int result=brute_max_product_subarray(arr);
    cout<<result;
    cout<<endl;
    int result1=optimal_max_product_subarray(arr1);
    cout<<result1;
    cout<<endl;

    return 0 ;
}