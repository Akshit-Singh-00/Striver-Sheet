#include<bits/stdc++.h>
using namespace std;

int brute_missing_number(vector<int> arr){
     int n=arr.size()+1;
     for(int i=1;i<=n;i++){
        bool found=false;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
               found=true;
            }
        }
        if(!found){
            return i;
        }
     }
     return -1;
} // T.c -> O(n^2) s.c -> O(1)


int better_missing_number(vector<int> arr){
    int n=arr.size()+1;
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<n+1;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
} // T.c ->O(2n) ; S.c-> O(n)

int optimal1_missing_number(vector<int> arr){
    int n=arr.size()+1;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        sum1=sum1+arr[i];
    }
    sum2=(n*(n+1))/2;

    return sum2-sum1;
} // T.c->O(n);S.c->O(1)

int optimal2_missing_number(vector<int> arr){
    int n=arr.size()+1;
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    for(int i=1;i<=n;i++){
        xor2=xor2^i;
    }
    return xor1^xor2;
      
}

int main(){
        vector<int> arr = {6, 2, 4, 5, 3, 7, 1}; 
    cout << brute_missing_number(arr) << endl; 
    cout<<better_missing_number(arr)<<endl;
    cout<<optimal1_missing_number(arr)<<endl;
    cout<<optimal2_missing_number(arr)<<endl;
    return 0 ;
}