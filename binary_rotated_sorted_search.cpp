#include <bits/stdc++.h>
using namespace std;
int brute_rotated_sorted_search(vector<int> arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
} // t.c->O(n);s.c->O(1)

int optimal_binary_rotated_search(vector<int> arr, int target)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[l] == mid && arr[r] == mid)
        {
            l++;
            r--;
            continue;
        }
        if (arr[l] <= arr[mid])
        {
            if (arr[l] <= target && target <= arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (arr[mid]<=target && target<=arr[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int t = 3;
    int result = brute_rotated_sorted_search(arr, t);
    cout << result << endl;
    int result1=optimal_binary_rotated_search(arr,t);
    cout<<result1;
    return 0;
}