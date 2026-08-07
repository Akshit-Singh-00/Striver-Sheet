#include<bits/stdc++.h>
using namespace std;

int brute_first_occurence(vector<int> arr,int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cnt++;
        }
    }
    return cnt;
}//t.c->O(n);s.c->O(1)

int main(){
    vector<int> a={2, 2 , 3 , 3 , 3 , 3 , 4};
    int x=3;
    int result=brute_first_occurence(a,x);
    cout<<result<<endl;

    return 0 ;
}