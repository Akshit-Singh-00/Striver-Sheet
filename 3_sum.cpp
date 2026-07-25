#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_3_sum(vector<int>& arr, int target) {

    set<vector<int>> st;

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                if (arr[i] + arr[j] + arr[k] == target) {

                    vector<int> temp = {arr[i], arr[j], arr[k]};

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}//t.c->O(n^3)*(log(unique element));s.c->O(2*number of triplets)

int main() {

    vector<int> arr = {-1,0,1,2,-1,-4};

    int target = 0;

    vector<vector<int>> ans = brute_3_sum(arr, target);

    for (auto &triplet : ans) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}