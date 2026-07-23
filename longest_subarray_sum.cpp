#include<bits/stdc++.h>
using namespace std;

int brute_longest_subarray_sum(vector<int> arr,int key){
    int maxlength=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum==key){
                maxlength=max(maxlength,j-i+1);
            }
        }
    }
    return maxlength;
}// t.c->O(n^3);s.c->O(1)

int optimal_longest_subarray_sum(vector<int> arr,int k){
    int maxlen=0;
    int left,right=0;
    int sum=0;
    while(right<arr.size()){


       while(left<=right && sum>=k ){
        sum=sum-arr[left]+1;
        left++;
       }
         if(sum == k) {
                maxlen = max(maxlen, right - left + 1);
            }
            
            right++;
            if(right < arr.size()) sum += arr[right];
    }
    return maxlen;

}//t.c->O(n);s.c->O(1)


int main(){
    vector<int> vec={10, 5, 2, 7, 1, 9};
vector<int> vec1={-3, 2, 1};
int k1=6;
    int k=15;
    int resullt=brute_longest_subarray_sum(vec,k);
    cout<<resullt<<endl;
    int resullt1=brute_longest_subarray_sum(vec1,k1);
    cout<<resullt1<<endl;

    return 0 ;
}