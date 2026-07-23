#include <bits/stdc++.h>
using namespace std;

bool brute_linear_search(vector<int> arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int brute_longest_consecutive_sequence(vector<int> arr)
{
    int n = arr.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int cnt = 1;
        while (brute_linear_search(arr, x + 1))
        {
            x++;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
} // t.c->O(n^2);s.c->O(1)

int better_longest_consecutive_sequence(vector<int> arr)
{
    int lastsecond = INT_MIN;
    int longest = 1;
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == lastsecond)
        {
            count++;
        }
        else if (arr[i] != lastsecond)
        {
            lastsecond = arr[i];
            count = 1;
        }
        longest = max(longest, count);
    }
    return longest;
} // t.c->O(nlogn) ; s.c->O(1)

int optimal_longest_consecutive_sequence(vector<int> arr)
{
    int n = arr.size();
    set<int> st;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}//t.c->O(n) ;s.c->O(n)

int main()
{
    vector<int> vec = {100, 4, 200, 1, 3, 2};
    int result = brute_longest_consecutive_sequence(vec);
    cout << result << endl;
    vector<int> vec1 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int result1 = brute_longest_consecutive_sequence(vec1);
    cout << result1 << endl;
    int result12 = optimal_longest_consecutive_sequence(vec1);
    cout << result12 << endl;

    return 0;
}