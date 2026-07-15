#include<bits/stdc++.h>
using namespace std;

void brute1_union(vector<int> arr1 ,int  n , vector<int> arr2,int m ){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr1[i]]++;
    }
    for(int j=0;j<m;j++){
        mp[arr2[j]]++;
    }
vector<int> ans;
for(auto it :mp){
    ans.push_back(it.first);
}
for(auto it:ans){
    cout<<it<<" ";
}
} // t.c-> O( (m+n)log(m+n) ) ; s.c->O(m+n)

void brute2_union(vector<int> arr1 ,int  n , vector<int> arr2,int m ){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        s.insert(arr2[i]);
    }
    vector<int> ans(s.begin(),s.end());
    for(auto it :ans){
        cout<<it<<" ";
    }
} // T.c ->O( (m+n)log(m+n) );S.c-> O(n+m)

vector<int> optimal_union(vector<int> arr1 ,int  n , vector<int> arr2,int m ){
    vector<int> Unionn;
    int i=0;
    int j=0;
   while (i < n && j < m) {
          
            if (arr1[i] < arr2[j]) {
               
                if (Unionn.empty() || Unionn.back() != arr1[i])
                    Unionn.push_back(arr1[i]);
                i++;  
            }
            
            else if (arr2[j] < arr1[i]) {
               
                if (Unionn.empty() || Unionn.back() != arr2[j])
                    Unionn.push_back(arr2[j]);
                j++;  
            }
            else {
                
                if (Unionn.empty() || Unionn.back() != arr1[i])
                    Unionn.push_back(arr1[i]);
                i++; j++;  
            }
        }

        
        while (i < n) {
            if (Unionn.empty() || Unionn.back() != arr1[i])
                Unionn.push_back(arr1[i]);
            i++;
        }

       
        while (j < m) {
            if (Unionn.empty() || Unionn.back() != arr2[j])
                Unionn.push_back(arr2[j]);
            j++;
        }

       
        return Unionn;
    } // T.c->O(n+m) ; s.c->O(n+m)


int main(){
    vector<int> a1={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> a2={2, 3, 4, 4, 5, 11, 12};
    int n=a1.size();
    int m=a2.size();
    brute1_union(a1,n,a2,m);
    cout<<endl;
    brute2_union(a1,n,a2,m);
    cout<<endl;
    vector<int> v=optimal_union(a1,n,a2,m);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0 ;
}