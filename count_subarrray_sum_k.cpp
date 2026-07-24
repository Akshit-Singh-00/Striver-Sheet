#include <bits/stdc++.h>
using namespace std;
int brute_count_subarrray_sum_k(vector<int> arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == target)
            {
                count++;
            }
        }
    }
    return count;
} // t.c->O(n^3);s.c->O(1)

int better_count_subarrray_sum_k(vector<int> arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
} // t.c->O(n^2);s.c->O(1)

int optimal_count_subarray_sum_k(vector<int> arr,int k){
    unordered_map<int,int> mp;
    int count=0;
    int prefixsum=0;
    mp[0]=1;
    for(auto it:arr){
        prefixsum+=it;
        int remove=prefixsum-k;
        if(mp.find(remove)!=mp.end()){
            count+=mp[remove];
        }
        mp[prefixsum]++;
    }
    return count;
}//t.c->O(n) ; s.c->O(n)

int main()
{
    vector<int> vec = {1, 2, 3};
    vector<int> vec1 = {3, 1, 2, 4};
    int target1 = 6;
    int target = 3;
    int result1 = brute_count_subarrray_sum_k(vec, target);
    cout << result1 << endl;
    int result12 = better_count_subarrray_sum_k(vec1, target1);
    cout << result12 << endl;
    int result123 = optimal_count_subarray_sum_k(vec1, target1);
    cout << result123 << endl;
    return 0;
}