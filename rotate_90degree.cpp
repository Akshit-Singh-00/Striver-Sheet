#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_rotate_90degree(vector<vector<int>> arr){
    int n=arr.size();
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[j][n-i-1]=arr[i][j];
        }
    }
    return v;
} // t.c->O(n^2) ; s.c->O(n^2)

vector<vector<int>> optimal(vector<vector<int>> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
} // t.c->O(n^2) ; s.c->O(1)

int main(){
    vector<vector<int>> a={{1,2,3},{4,5,6},{7,8,9}};
     vector<vector<int>> result=brute_rotate_90degree(a);
     for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
     }
cout<<endl;
      vector<vector<int>> result1=brute_rotate_90degree(a);
     for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            cout<<result1[i][j]<<" ";
        }
        cout<<endl;
     }

    return 0 ;
}