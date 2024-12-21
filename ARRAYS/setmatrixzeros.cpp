#include<bits/stdc++.h>
using namespace std;

//brute approach
// void makeRow(vector<vector<int>> &mat,int i,int m)
// {
// for(int j=0;j<m;j++)
// {
//     if (mat[i][j]!=0)
//     {
//         mat[i][j]=-1;
//     }
// }
// }
// void makeCol(vector<vector<int>> &mat,int j,int n)
// {
//   for(int i=0;i<n;i++)
// {
//     if (mat[i][j]!=0)
//     {
//         mat[i][j]=-1;
//     }
// }  
// }

// vector<vector<int>> matrixsetzeros(vector<vector<int>> mat,int n,int m)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//     {
//         if (mat[i][j]==0)
//         {
//             makeRow(mat,i,m);
//             makeCol(mat,j,n);
//         }
//     }
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if (mat[i][j]==-1)
//             {
//                 mat[i][j]=0;
//             }
//         }
//     }
//     return mat;
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------


//better solution
vector<vector<int>> matrixsetzeros(vector<vector<int>> mat,int n,int m)
{
    int rowMatrix[n]={0};
    int colMatrix[m]={0};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (mat[i][j]==0)
            {
                rowMatrix[i]=1;
                colMatrix[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (rowMatrix[i]==1 || colMatrix[j]==1)
            {
                mat[i][j]=0;
            }
        }
    }
    return mat;
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> result=matrixsetzeros(mat,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
  
}
