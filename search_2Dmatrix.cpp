#include<bits/stdc++.h>
using namespace std;

bool brute_2Dmatrix(vector<vector<int>> arr,int target){
      int n=arr.size();
      int m=arr[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
      }
      return false;
      
}//t.c->O(n*m) ; s.c->O(1)


bool binary_search(vector<int>arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(target>arr[mid]){
             low=mid+1;
        }
        else{
            high=mid-1;
        }
        return false;
    }
    
}
bool better_2Dmatrix(vector<vector<int>> arr,int target){
int n=arr.size();
int m=arr[0].size();
for(int i=0;i<n;i++){
    if(arr[i][0]<=target && target<=arr[i][m-1]){
        return binary_search(arr[i],target);
    }
}
return false;

} // t.c->O(n*logm) ; s.c->O(1)

bool optimal_2Dmatrix(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();

    int low=0;
    int high=n*m-1;
    while(low<high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}//t.c->O(log(n*m));s.c->O(1)

int main(){
    vector<vector<int>> vec={{1,2,3},
    {4,5,6},
    {7,8,9}};
    int t;
    cin>>t;
    bool result=brute_2Dmatrix(vec,t);
    if(result){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;
    }

    bool result1=brute_2Dmatrix(vec,t);
    if(result1){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;
    }
    bool result2=brute_2Dmatrix(vec,t);
    if(result2){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;
    }
    return 0 ;
}