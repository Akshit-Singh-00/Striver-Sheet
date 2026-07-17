#include<bits/stdc++.h>
using namespace std;

void brute_stock_buy_sell(vector<int> arr){
    int maxProfit=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            int price=arr[j]-arr[i];
            maxProfit=max(maxProfit,price);
        }
    }
    cout<<maxProfit<<endl;
} // T.c->O(n^2);s.c->O(1)

void optimal_stock_buy_sell(vector<int> arr){
    int minPrice=INT_MAX;
    int maxProfit=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        else{
            maxProfit=max(maxProfit,arr[i]-minPrice);
        }
    }
  cout<< maxProfit;
} // T.c->O(n); S.c->O(1)

int main(){
    vector<int> result={7,1,5,3,6,4};
    brute_stock_buy_sell(result);
    optimal_stock_buy_sell(result);
    return 0 ;
}