#include<bits/stdc++.h>
using namespace std;

vector<int> brute_repeating_missing(vector<int> arr)
{
    int n=arr.size();
    int repeat=-1,missing=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i+1){
                count++;
            }
        }
        if(count==2){
            repeat=i+1;
        }
        else if(count==0){
            missing=i+1;
        }
        if(repeat!=-1 && missing !=-1){
            break;
        }
    }
    return {repeat,missing};
}//t.c->O(n^2);s.c->O(1)

vector<int> better_repeating_missing(vector<int> arr){
    int n=arr.size();
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int repeating=-1,missing=-1;
    for(int i=1;i<=n;i++){
        
        if(hash[i]==2){
            repeating=i;
        }
        else if(hash[i]==0){
            missing=i;
        }
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    return {repeating,missing};

}//t.c-z>O(2n);s.c->O(n)

vector<int> optimal_repeating_missing(vector<int> arr)
{
    int n = arr.size();

    long long sn = 1LL * n * (n + 1) / 2;
    long long s2n = 1LL * n * (n + 1) * (2 * n + 1) / 6;

    long long s = 0, s2 = 0;

    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += 1LL * arr[i] * arr[i];
    }

    long long val1 = s - sn;      // x - y
    long long val2 = s2 - s2n;    // x² - y²

    val2 = val2 / val1;           // x + y

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}//t.c->O(n);s.c->O(1)

int main(){
    vector<int> arr={3, 5, 4, 1, 1};
    vector<int> arr1={1, 2, 3, 6, 7, 5, 7};
    vector<int> result=brute_repeating_missing(arr);
    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result1=better_repeating_missing(arr1);
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> result12=optimal_repeating_missing(arr1);
    for(auto it:result12){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0 ;
}