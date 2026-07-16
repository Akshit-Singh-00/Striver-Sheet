#include<bits/stdc++.h>
using namespace std;

vector<int> brute_leader(vector<int>arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
    for(int j=i+1;j<n;j++){
        if(arr[j]>=arr[i]){
            leader=false;
            break;
        }
    }
    if(leader){
        ans.push_back(arr[i]);
    }
    }
    return ans;
} // T.c->O(n^2) ;s.c->O(1)=as using constant space to store limited integer numbers

vector<int> optimal_leader(vector<int> arr){
int n=arr.size();
int max=arr[n-1];
vector<int>ans;
ans.push_back(arr[n-1]);
for(int i=0;i<n;i++){
if(arr[i]>max){
    ans.push_back(arr[i]);
    max=arr[i];
}
}
reverse(ans.begin(),ans.end()); // n/2
return ans;
}//T.c->O(n+n/2) ; s.c->O(1)

int main(){
    vector<int> vec={10,22,12,3,0,6};
    vector<int> result1=brute_leader(vec);
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result2=brute_leader(vec);
    for(auto it:result2){
        cout<<it<<" ";
    }
    cout<<endl;
    
    return 0 ;
}