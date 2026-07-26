#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_threesum(vector<int>& arr, int target) {

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

 vector<vector<int>> better_threeSum(vector<int>& arr, int n) {
 
        set<vector<int>> ans;


        for (int i = 0; i < n; i++) {
        
            set<int> hashset;

            for (int j = i + 1; j < n; j++) {
                
                int third = -(arr[i] + arr[j]);

                
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }

                
                hashset.insert(arr[j]);
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }//t.c->O(2*n(log(number of unique triplets)));s.c->O((2 * no. of the unique triplets) + O(N) )

 vector<vector<int>> optimal_threeSum(vector<int>& arr, int n) {
       
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;

       
        for (int i = 0; i < n; i++) {
            
            if (i > 0 && arr[i] == arr[i - 1]) continue;

        
            int left = i + 1, right = n - 1;

       
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++, right--;

                    
                    while (left < right && arr[left] == arr[left - 1]) left++;
                  
                    while (left < right && arr[right] == arr[right + 1]) right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    } //t.c-.O(n(log(unique no. of triplets)));s.c->O(n)

int main() {

    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<int> arr1 = {-1,0,1,0};

    int target = 0;

    vector<vector<int>> ans = brute_threesum(arr, target);

    for (auto &triplet : ans) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
    vector<vector<int>> ans1 =better_threeSum(arr1, target);

    for (auto &triplet : ans1) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
    vector<vector<int>> ans12 =optimal_threeSum(arr, target);

    for (auto &triplet : ans12) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}