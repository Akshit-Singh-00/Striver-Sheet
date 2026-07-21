#include<bits/stdc++.h>
using namespace std;

vector<int> brute_majority_elements2(vector<int> arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ans.size()==0 || ans[0]!=arr[i]){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]){
                    cnt++;
                }
            }
            if(cnt>n/3){
                ans.push_back(arr[i]);
            }
            if(ans.size()==2)break;
        }
    }
    return ans;
}//t.c->O(n^2);s.c->O(1)


vector<int> better_majority_elements2(vector<int> arr){
    int n=arr.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    int mini=n/3;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==mini){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2){
            break;
        }
    }
    return ans;

}//O(n*logn) ; s.c->O(n)

vector<int> optimal_majority_elements2(vector<int> arr){
    vector<int> ans;
    int n=arr.size();
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<n;i++){
       if(cnt1==0 || el2!=arr[i]){
        cnt1=1;
        el1=arr[i];
       }
       else if(cnt2==0 || el1!=arr[i]){
        cnt2=1;
        el2=arr[i];
       }
       else if(el1==arr[i]){
        cnt1++;
       }
       else if(el2==arr[i]){
        cnt2++;
       }
       else{
        cnt1--;
        cnt2--;
       }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]){
            cnt1++;
        }
        if(el2==arr[i]){
            cnt2++;
        }
    }
    int mini=n/3;
    for(int i=0;i<n;i++){
        if(cnt1>=mini){
            ans.push_back(arr[i]);
        }
        if(cnt2>=mini && el1!=el2){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2)break;
    }
    return ans;
}//t.c->O(n) ; s.c->O(1)

int main(){
    vector<int> vec={1, 2, 1, 1, 3, 2, 2};
    vector<int>result=brute_majority_elements2(vec);
    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>result1=better_majority_elements2(vec);
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>result11=optimal_majority_elements2(vec);
    for(auto it:result11){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0 ;
}