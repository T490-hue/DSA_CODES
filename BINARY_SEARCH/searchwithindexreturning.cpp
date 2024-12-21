#include<bits/stdc++.h>
using namespace std;


// pair<int,int>indexofseacrch(vector<vector<int>>& arr,int n,int m,int target)
// {
//     int row=0;
//     int col=m-1;
//     while (row<n && col>=0)
//     {
//         if (arr[row][col]==target)
//             return {row,col};
//         else if (arr[row][col]>target)
//             col--;
//         else
//             row++;
//     }
//     return {-1,-1};
// }

int main()
{
    vector<vector<int>> arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int n=arr.size();
    int m=arr[0].size();
    int target=14;
    pair<int,int> found=indexofseacrch(arr,n,m,target);
    cout<<found.first<<found.second;
    return 0;

}