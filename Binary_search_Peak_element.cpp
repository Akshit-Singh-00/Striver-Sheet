#include<bits/stdc++.h>
using namespace std;

int brute_BS_search_peak_element(vector<int> arr){
    int n=arr.size();
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
            return i;
        }
    }
    if(arr[n-1]>=arr[n-2]){
        return n;
    }
    return -1;
}//t.c->O(n) ; S.c->O(1)




int main(){
    
    vector<int> a={1,2,3,4,5,6,7,8,5,1};
    cout<<"Index is : "<<brute_BS_search_peak_element(a)<<endl;

    return 0 ;
}