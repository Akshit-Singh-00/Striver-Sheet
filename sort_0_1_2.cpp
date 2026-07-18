#include<bits/stdc++.h>
using namespace std;

vector<int> brute_sort_0_1_2(vector<int> arr){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
           if(arr[i]==0){
            cnt0++;
           }
           else if(arr[i]==1){
            cnt1++;
           }
           else{
            cnt2++;
           }
    }
    int index=0;
    while(cnt0--){
        arr[index]=0;
        index++;
    }
    while (cnt1--)
    {
        arr[index]=1;
        index++;
    }
    while (cnt2--)
    {
        arr[index]=2;
        index++;
    }
    return arr;
    
} // t.c->O(n);s.c->O(1)

vector<int> better_sort_0_1_2(vector<int> arr){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }
    for(int i=cnt0;i<cnt0+cnt1;i++){
        arr[i]=1;
    }
    for(int i=cnt0+cnt1;i<arr.size();i++){
        arr[i]=2;
    }
    return arr;
} // t.c->O(n) ; s.c->O(1)

//duch national flag algoritm
vector<int> optimal_sort_0_1_2(vector<int> arr){
    int high=arr.size()-1;
    int low=0;
    int mid=0;
    while(mid<high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}

int main(){
    vector<int> a={0,1,2,2,1,0,1,2,0};
    vector<int> result=brute_sort_0_1_2(a);
    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result1=brute_sort_0_1_2(a);
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result12=brute_sort_0_1_2(a);
    for(auto it:result12){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0 ;
}