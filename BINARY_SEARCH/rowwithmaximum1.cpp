#include<bits/stdc++.h>
using namespace std;


// int rowwithmax1(vector<vector<int>>& mat,int n,int m)
// {
//     int maxi=-1;
//     int cnt;
//     int index=-1;

//     for(int i=0;i<n;i++)
//     {
//         cnt=0;
//         for(int j=0;j<m;j++)
//         {
//             if (mat[i][j]==1)
//             {
//                 cnt++;
//             }
//         }
//         if (cnt>maxi){
//         maxi=cnt;
//         index=i;
//         }
//     }
//         return index;

// }
// ---------------------------------------------------------------------------------------------------------------------------------------------------
// int rowwithmax1(vector<vector<int>>& mat,int n,int m)
// {
//     int maxi=-1;
//     int cnt;
//     int index=-1;

//     for(int i=0;i<n;i++)
//     {
//         cnt=0;
//         for(int j=0;j<m;j++)
//         {
            
//                 cnt+=mat[i][j];
            
//         }
//         if (cnt>maxi){
//         maxi=cnt;
//         index=i;
//         }
//     }
//         return index;

// }
// ----------------------------------------------------------------------------------------------------------------------------------------------------------
int lowerbound(vector<int>& a,int m,int x)
{
int low=0;
int high=m-1;
int ans=m;
while (low<=high)
{
    int mid=(low+high)/2;
    if (a[mid]>=1)
    {
        ans=mid;
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
}
return ans;
}
int rowwithmax1(vector<vector<int>> arr,int n,int m)
{
    int cnt_max=-1;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        int occurenceof1=lowerbound(arr[i],m,1);
        int cnt=m-occurenceof1;
        if (cnt>cnt_max)
        {
            cnt_max=cnt;
            index=i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr={{0,0,1,1,1},{0,0,0,0,0},{0,0,0,0,0},{0,1,1,1,1},{1,1,1,1,1},};
    int n=arr.size();
    int m=arr[0].size();
    int rowwithmax1s=rowwithmax1(arr,n,m);
    cout<<rowwithmax1s;
    return 0;
}