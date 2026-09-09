#include <bits/stdc++.h>
using namespace std;

int brute_BS_cuberoot(int n, int m)
{
    int ans;
    for (int i = 0; i < m; i++)
    {
        int power = pow(i, n);
        if (power == m)
        {
            ans = i;
            break;
        }
    }
    return ans;
} // t.c->O(m);s.c->O(1)

int optimal_BS_cuberoot(int n, int m)
{
    int l = 0;
    int h = m - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans *= mid;

            if (ans > m)
                break;
        }

        if (ans == m)
            return mid;

        else if (ans < m)
            l = mid + 1;

        else
            h = mid - 1;
    }

    return -1;
}//t.c->O(logn);s.c->O(1)

int main()
{

    int n = 3;
    int m = 27;
    cout << "The number is : " << brute_BS_cuberoot(n, m) << endl;
    cout << "The number is : " << optimal_BS_cuberoot(n, m) << endl;
    return 0;
}