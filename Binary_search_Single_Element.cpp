#include<bits/stdc++.h>
using namespace std;

int brute_BS_Single_Element(vector<int> arr){
    int n=arr.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans^=arr[i];
    }
    return ans;
    
}//t.c->O(n);s.c->O(1)

int optimal__BS_Single_Element(vector<int> arr){
     int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1)
                mid--;

            if (arr[mid] == arr[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }

        return arr[low];
}//t.c->O(logn);s.c->O(1)


int main(){
    vector<int> a={1,1,2,2,3,3,4,5,5,6,6};
    cout<<"element is - "<<brute_BS_Single_Element(a)<<endl;
    cout<<"Element is  - "<<optimal__BS_Single_Element(a);

    return 0 ;
}