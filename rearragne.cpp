#include<bits/stdc++.h>
using namespace std;

vector<int> brute_rearrange(vector<int> arr){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            pos.emplace_back(arr[i]);
        }
        else{
            neg.emplace_back(arr[i]);
        }
    }
    for(int i=0;i<arr.size()/2;i++){
         arr[2*i]=pos[i];
         arr[2*i+1]=neg[i];
    }
    return arr;
}// t.c->O(n+n/2) ; s.c->O(n/2+n/2)

vector<int> optimal_rearrange(vector<int> arr){
    vector<int> ans;
int n=arr.size();
int pos=0;
int neg=1;
for(int i=0;i<n;i++){
    if(arr[i]>0){
        ans[pos]=arr[i];
        pos++;
    }
    else{
        ans[neg]=arr[i];
        neg+2;
    }
}
return ans;
} // t.c->O(n);s.c->O(n)

int main(){
    vector<int> a={1,-2,3,4,-4,-6};
    vector<int> result=brute_rearrange(a);
    for(auto it : result){
        cout<<it<<" ";
    }
    cout<<endl;

vector<int> result1=brute_rearrange(a);
    for(auto it : result1){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0 ;
}