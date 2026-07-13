#include<bits/stdc++.h>
using namespace std;

void brute_2nd_largest_smallest(int arr[],int n){
sort(arr,arr+n);

int ss=arr[1];
int sl=arr[n-2];
cout<<ss<<endl;
cout<<sl<<endl;

} // T.c -> O(nlogn) ; S.c -> O(1)

void better_2nd_largest_smallest(int arr[],int n){
    int s=INT_MAX,ss=INT_MAX;
    int l=INT_MIN,sl=INT_MIN;
    for(int i=0;i<n;i++){
        s=min(s,arr[i]);
        l=max(l,arr[i]);
    }
  for(int i=0;i<n;i++){
    if(arr[i]<ss && arr[i]!=s){
        ss=arr[i];
    }
    if(arr[i]>sl && arr[i]!=l){
        sl=arr[i];
    }
  }

  cout<<ss<<endl;
  cout<<sl<<endl;
} // T.c -> O(2n) ; S.c -> O(1)

void  optimal_2nd_largest(int arr[],int n){
    int ss=INT_MIN,s=INT_MIN;
    for(int i=0;i<n;i++){
    if(arr[i]>s){
        ss=s;
        s=arr[i];
    }
    if(arr[i]>ss && arr[i]!=s){
        ss=arr[i];
    }
    }
    cout<<ss<<endl;
} // T.c -> O(n) ; S.c ->O(1)

void optimal_2nd_smallest(int arr[],int n){
    int l=INT_MAX,sl=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<l){
            sl=l;
            l=arr[i];
        }
            if(arr[i]<sl && arr[i]!=l){
                sl=arr[i];
            
        }
    }
    cout<<sl<<endl;

}//T.c -> O(n) ; S.c -> O(1)

int main(){
    
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // brute_2nd_largest_smallest(arr,n);
    // better_2nd_largest_smallest(arr,n);
    // optimal_2nd_largest(arr,n);
    optimal_2nd_smallest(arr,n);

    return 0 ;
}