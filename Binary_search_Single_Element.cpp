#include<bits/stdc++.h>
using namespace std;

int brute_BS_Single_Element(vector<int> arr){
    int n=arr.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans^=arr[i];
    }
    return ans;
    
}

int main(){
    vector<int> a={1,2,3,4,1,2,3,5,4};
    cout<<"element is - "<<brute_BS_Single_Element(a)<<endl;

    return 0 ;
}