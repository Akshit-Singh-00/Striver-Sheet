#include <bits/stdc++.h>
using namespace std;

int brute_duplicate_remove(vector<int>& arr) {
    unordered_set<int> s;
    int index = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);      
            arr[index] = arr[i];    
            index++;
        }
    }

    return index;
} // T.c -> O(n) ; S.c -> O(n)

int optimal_duplicate_remove(vector<int> arr){

    int i =0;
    for(int j=0;j<arr.size();j++){
        if(arr[i]!=arr[j]){
           i++;
           arr[i]=arr[j];
        }
    }
    return i+1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = brute_duplicate_remove(nums);
    int k1=optimal_duplicate_remove(nums);

    cout << "k = " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout<<endl;
    for(int i=0;i<k1;i++){
        cout<<nums[i]<<" ";
    }
        return 0;
}