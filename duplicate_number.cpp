#include<bits/stdc++.h>
using namespace std;

int brute_findDuplicate(vector<int>& arr) {
 
  int n = arr.size();
  
  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 1; i++) {

    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
 
  return -1;
} // T.c ->O(nlogn);s.c->O(1)


int better_findDuplicate(vector<int> arr){
    int n=arr.size();
    vector<int>hash(n+1,0);
    for(int i=0;i<n;i++){
        if(hash[arr[i]]==0){
            hash[arr[i]]+=1;
        }
        else{
            return arr[i];
        }
    }
    return 0;

} // t.c->O(n) ;s.c->O(n)

//Floyd Cycle Detection
int optimal_findDuplicate(vector<int> arr){
    int slow=arr[0];
    int fast=arr[0];
    do
    {
            slow=arr[slow];
            fast=arr[arr[fast]];
    } while (slow!=fast);
    fast=arr[0];
    while (slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
    
}//t.c->O(n) ; s.c->O(1)

int main(){

    vector<int> vec={1,2,3,3};
 int result=brute_findDuplicate(vec);
 cout<<result;
cout<<endl;
 int result2=better_findDuplicate(vec);
 cout<<result2;
cout<<endl;
int result3=optimal_findDuplicate(vec);
 cout<<result3;
 
    return 0 ;
}