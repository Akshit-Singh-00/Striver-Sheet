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



int main(){
    vector<int> arr={1,2,3,4,5,0};
    int result=brute_max_product_subarray(arr);
    cout<<result;
    cout<<endl;

    return 0 ;
}