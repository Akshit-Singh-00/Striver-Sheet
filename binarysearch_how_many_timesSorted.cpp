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
}//t.c->O(n);s.c->O(1)

int better_BS_how_manyTimes_sorted(vector<int> arr){
    int n=arr.size();
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            return i+1;
        }
    }
    return -1;
    
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout<<" result-> "<<brute_BS_how_manyTimes_sorted(arr)<<endl;
    cout<<" result-> "<<better_BS_how_manyTimes_sorted(arr)<<endl;

    return 0 ;
}