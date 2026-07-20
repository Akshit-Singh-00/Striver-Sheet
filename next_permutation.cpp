#include<bits/stdc++.h>
using namespace std;

 vector<int> brute_nextpermutation(vector<int>& nums) {

        vector<vector<int>> all;


        sort(nums.begin(), nums.end());
        do {
            all.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));


        for (int i = 0; i < all.size(); i++) {
            if (all[i] == nums) {

                if (i == all.size() - 1)
                    return all[0];
            
                return all[i + 1];
            }
        }


        return nums;
    }//t.c->O(n!*n) ;s.c->O(n!)

    void optimal_nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                           
                index = i;
                break;
            }
        }
        if (index == -1) {

            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > index; i--) {
            // Swap the two
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }//t.c->O(n) ; s.c->O(1)


int main(){
    vector<int> nums={1,2,3};
    vector<int> result1=brute_nextpermutation(nums);
    for(auto it:result1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> num1={2,1,3};
   optimal_nextPermutation(num1);
    
       for (int num : nums) {
        cout << num << " ";
    }
    
    return 0 ;
}