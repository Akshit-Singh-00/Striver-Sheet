#include<bits/stdc++.h>
using namespace std;

int brute_kadans_algorithm(vector<int> arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
            maxi=max(maxi,sum);
        }
        
    }
    return maxi;

} // t.c->O(n^3) ; s.c->O(1)

int better_kadans_algorithm(vector<int>arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}//t.c->O(n^2) ; s.c->O(1)

int optimal_kadans_algorithm(vector<int> arr){
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    vector<int> a={2, 3, 5, -2, 7, -4};
    vector<int> b={-2, -3, -7, -2, -10, -4};
    int result=brute_kadans_algorithm(a);
    cout<<result<<endl;
    // int result1=brute_kadans_algorithm(a);
    int result1=brute_kadans_algorithm(b);
    cout<<result1<<endl;

int reseult3=optimal_kadans_algorithm(b);
cout<<reseult3;
    return 0 ;
}