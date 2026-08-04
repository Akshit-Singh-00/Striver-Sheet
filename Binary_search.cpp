#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr,int target){
int n=arr.size();
int low=0;
int high=n-1;

while (low<high)
{
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>mid){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return -1;

}//t.c->O(nlogn);s.c->O(1)

int main(){
    
vector<int> arr={1,2,3,4,5};
int k=40;
int result=binary_search(arr,k);
cout<<result;
    return 0 ;
}