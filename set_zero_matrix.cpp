#include <bits/stdc++.h>
using namespace std;

void brute_set_zero_matrix(vector<vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int col = 0; col < m; col++)
                {
                    if (arr[i][col] != 0)
                    {
                        arr[i][col] = -1;
                    }
                }
            
            for (int row = 0; row < n; row++)
            {
                if (arr[row][j] != 0)
                {
                    arr[row][j] = -1;
                }
            }
        }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}//t.c->O(m*n*(m+n))+O(n*m) ; s.c->O(1)

void better_set_zero_matrix(vector<vector<int>>& arr){
   
    int n=arr.size();
    int m=arr[0].size();
     vector<int> row(n,0);
    vector<int> col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
              row[i]=1;
              col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                arr[i][j]=0;
            }
        }
    }
} // t.c->O(n*m)+O(n*m);s.c->O(n+m)

void optimal_set_zero_matrix(vector<vector<int>>& arr){
int n=arr.size();
int m=arr[0].size();
bool isrowzero=false;
bool iscolzero=false;
for (int j = 0; j < n; j++) {
            if (arr[0][j] == 0) {
                isrowzero = true;
                break;
            }
        }

        
        for (int i = 0; i < m; i++) {
            if (arr[i][0] == 0) {
                iscolzero = true;
                break;
            }
        }

       
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] == 0) {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }

        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][0] == 0 || arr[0][j] == 0) {
                    arr[i][j] = 0;
                }
            }
        }

        
        if (isrowzero) {
            for (int j = 0; j < n; j++) {
                arr[0][j] = 0;
            }
        }

        
        if (iscolzero) {
            for (int i = 0; i < m; i++) {
                arr[i][0] = 0;
            }
        }
}//t.c->O(n*m) ; s.c->O(1)

int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    brute_set_zero_matrix(arr);
    for (auto it : arr)
    {
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
vector<vector<int>> arr2={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    better_set_zero_matrix(arr2);
    for (auto it : arr2)
    {
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    cout<<endl;
    vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 0, 6},
    {7, 8, 9}
};
optimal_set_zero_matrix(matrix);
for(auto it:matrix){
    for(auto val:it){
        cout<<val<<" ";
    }
    cout<<endl;
}
    return 0;
}