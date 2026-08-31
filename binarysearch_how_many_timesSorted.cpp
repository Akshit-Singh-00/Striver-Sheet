#include<bits/stdc++.h>
using namespace std;


int brute_BS_how_manyTimes_sorted(vector<int> arr){
    int n=arr.size();
    int minVal=arr[0];
    int minIndex=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<minVal){
            minVal=arr[i];
            minIndex=i;
        }
    }
    return minIndex;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout<<" result-> "<<brute_BS_how_manyTimes_sorted(arr);
    return 0 ;
}