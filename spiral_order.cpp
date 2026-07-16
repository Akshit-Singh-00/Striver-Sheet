#include<bits/stdc++.h>
using namespace std;

vector<int> spiral_order(vector<vector<int>> arr){
    vector<int>ans;
    int n=arr.size();
    int m=arr[0].size();
    int left=0;
    int top=0;
    int bottom=n-1;
    int right=m-1;
while (left<=right && top<=bottom)          
{
    for(int i=left;i<=right;i++){
        ans.push_back(arr[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
        ans.push_back(arr[i][bottom]);
    }
    right--;
    if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
    }
    bottom--;
    if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
        }
    }
    left++;
}
return ans;

}//t.c->O(n*m) ; s.c->O(1)

int main(){
    vector<vector<int>> vec={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> reult=spiral_order(vec);
    for(auto it:reult){
        cout<<it<<" ";
    }
    return 0 ;
}