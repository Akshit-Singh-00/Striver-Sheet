#include<bits/stdc++.h>
using namespace std;

   void brute_kth_place_left(vector<int> arr,int k){
    
        vector<int> ans;
        int  n=arr.size();
        k=k%n;
        for(int i=0;i<k;i++){
            ans.emplace_back(arr[i]);
        }
        for(int i=k;i<n;i++){
            arr[i-k]=arr[i];
        }
        for(int i=0;i<k;i++){
                arr[n-k+i]=ans[i];
        }
        for(auto it : arr){
            cout<<it<<" ";
        }
   } // T.c -> O(3n) , s.c -> O(n)

  void brute_kth_place_right(vector<int> arr,int k){
        int n=arr.size();
        vector<int> ans;
        k=k%n;
        for(int i=n-k;i<n;i++){
          ans[i-n+k]=arr[i];
        }
          for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }

        // Copy back the k elements to the start
        for (int i = 0; i < k; i++) {
            arr[i] = ans[i];
        }
        for(auto it:arr){
            cout<<it <<" ";
        }
  }// T.c -> O(3n) , s.c -> O(n)

 

int main(){

     vector<int> vec={1,2,3,4,5,6,7};
     int k;
     cin>>k;
     brute_kth_place_left(vec,k);
     cout<<endl;
     brute_kth_place_right(vec,k);
    return 0 ;
}