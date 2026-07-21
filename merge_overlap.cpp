#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

    
        vector<vector<int>> ans;

        
        int n = intervals.size();
        for (int i = 0; i < n; ) {

          
            int start = intervals[i][0];
            int end = intervals[i][1];

        
            int j = i + 1;
            while (j < n && intervals[j][0] <= end) {

                end = max(end, intervals[j][1]);
                j++;
            }

   
            ans.push_back({start, end});

            i = j;
        }

        return ans;
    } // t.c->O(n^2); s.c->O(1)
    

    vector<vector<int>> optimal_merge(vector<vector<int>> arr){
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(auto i:arr){
            if(ans.empty() || ans.back()[1]<i[0]){
                ans.push_back(i);
            }
            else{
                ans.back()[1]=max(ans.back()[1],i[1]);

            }
        }
        return ans;
    }

int main(){
    vector<vector<int>> arr = {{1,3}, {2,6},{8,10},{9,11}};

 vector<vector<int>> ans=brute_merge(arr);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}//t.c->O(n) ;s.c->O(1)
cout<<endl;
 vector<vector<int>> ans1=brute_merge(arr);
for(int i=0;i<ans1.size();i++){
    for(int j=0;j<ans1[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
    return 0 ;
}