#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_pascals_traingle(int numRow){
    vector<vector<int>> vec;
    for(int i=0;i<numRow;i++){
        vector<int> row(i+1,1);
        for(int j=1;j<i;j++){
           row[j]=vec[i-1][j-1]+vec[i-1][j];
        }
        vec.push_back(row);
    }
    return vec;
}//t.c->O(n^2) ; s.c->O(n^2)

vector<int> better_pascals_traingle(int numRow){
    vector<int> ans;
    int val=1;
    ans.push_back(val);
    for(int i=1;i<numRow;i++){
        val=val*(numRow-i)/i;
        ans.push_back(val);
    }
    return ans;
}//t.c->O(n) ; s.c-O(n)

int optimal_pascals_traingle(int r,int c){
    int n=r-1;
    int m=c-1;
    int ans=1;
    for(int i=0;i<m;i++){
      ans*=(n-i);
      ans/=(i+1);
    }
    return ans;
}//t.c->O(n) ; s.c->O(1)

int main(){
    int numRow=5;
    vector<vector<int>> ans=brute_pascals_traingle(numRow);
    for(int i=0;i<numRow;i++){
        for(int j=0;j<ans[i].size();j++){
cout<<ans[i][j] <<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;
    vector<int> ans1=better_pascals_traingle(numRow);
    for(int i=0;i<numRow;i++){
cout<<ans1[i] <<" ";
       
    }
    cout<<endl;
    cout<<endl;

    int ans3=optimal_pascals_traingle(5,3);
    cout<<ans3;
    
    return 0 ;
}