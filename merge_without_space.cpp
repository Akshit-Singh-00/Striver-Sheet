#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr1, int m, vector<int>& arr2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        else
        {
            arr1[k--] = arr2[j--];
        }
    }

    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }
}

int main()
{
    vector<int> nums1 = {1,3,5,0,0,0};
    vector<int> nums2 = {2,4,6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";

    return 0;
}