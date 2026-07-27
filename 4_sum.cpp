#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_4_sum(vector<int> arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
} // t.c->O(n^4 * log(no. of unique quadriplet)) ;s.c->O(2* no. of unique quadiplet)

vector<vector<int>> better_4_sum(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_set<int> seen;

            for (int k = j + 1; k < n; k++)
            {
                long long required = (long long)target - arr[i] - arr[j] - arr[k];

                if (seen.count(required))
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                seen.insert(arr[k]);
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
} // t.c->O(n^3*logM);s.c->O(2*n)

vector<vector<int>> optimal_4_sum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum = (long long)arr[i] + arr[j] +
                                arr[left] + arr[right];

                if (sum == target)
                {
                    ans.push_back({arr[i], arr[j],
                                   arr[left], arr[right]});

                    while (left < right && arr[left] == arr[left + 1])
                        left++;
                    while (left < right && arr[right] == arr[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return ans;
}//t.c->O(n^2);s.c->O(n)

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    vector<int> arr1 = {4,3,3,4,4,2,1,2,1,1};
    int target = 0;
    int target1 = 9;

    vector<vector<int>> ans = brute_4_sum(arr, target);

    for (auto quad : ans)
    {
        for (int num : quad)
            cout << num << " ";
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> ans1 = brute_4_sum(arr, target);

    for (auto quad1 : ans1)
    {
        for (int num : quad1)
            cout << num << " ";
        cout << endl;
    }
    cout<<endl;
    vector<vector<int>> ans12 = brute_4_sum(arr1, target1);

    for (auto quad12 : ans12)
    {
        for (int num : quad12)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}