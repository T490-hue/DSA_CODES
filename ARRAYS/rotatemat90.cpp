#include<bits/stdc++.h>
using namespace std;
//brute approach
// vector<vector<int>> matrixallzeros(vector<vector<int>> mat,int n)
// {
//     vector<vector<int>> rotated(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             rotated[j][(n-1)-i]=mat[i][j];
//         }
//     }

//     return rotated;
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------

//optimal solution

vector<vector<int>> matrixallzeros(vector<vector<int>> mat,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    //reverse each row
    for(int i=0;i<n;i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }
    return mat;
}
int main()
{
    vector<vector<int>> arr =  {{1, 2, 3,4}, {5, 6,7,8}, {9, 10,11,12},{13,14,15,16}};
    int n=arr.size();
    vector<vector<int>> result=matrixallzeros(arr,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}