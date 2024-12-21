#include<bits/stdc++.h>
using namespace std;


// vector<int> peakelementin2darray(vector<vector<int>>& arr,int n,int m)
// {
//     vector<int> result;
//    for(int i=0;i<n;i++)
//    {
//     for(int j=0;j<m;j++)
//     {
//         if (i>0) // checking for the top element
//             {
//                 if (arr[i][j]<arr[i-1][j])
//                     continue;
//             }
//         if (i<n-1) //checking for the bottom element
//         {
//             if (arr[i][j]<arr[i+1][j])
//                 continue;
//         }
//         if (j>0) //checking for left element
//         {
//             if (arr[i][j]<arr[i][j-1])
//                 continue;
//         }
//         if (j<m-1)//checking for the right element
//         {
//             if (arr[i][j]<arr[i][j+1])
//                 continue;
//         }
//         result.push_back(i);
//         result.push_back(j);
//         break;
//     }
//    }
//    return result;
// }

// --------------------------------------------------------------------------------------------------------------------------------------------------------

//optimal solution

int findmax(vector<vector<int>> arr,int n,int m,int col)
{
    int maxi=-1;
    int row=-1;
    for(int i=0;i<n;i++)
    {
        if (arr[i][col]>maxi)
        {
            maxi=arr[i][col];
            row=i;
        }
    }
    return row;
}
vector<int> peakelementin2darray(vector<vector<int>>& arr,int n,int m)
{
int low=0;
int high=m-1;
while(low<=high)
{
    int mid=(low+high)/2;
    int row=findmax(arr,n,m,mid);
    int left=0;
    int right=0;
    left=(mid-1)>=0 ? arr[row][mid-1]:-1;
    right=(mid+1)<m ? arr[row][mid+1]:-1;
    if (arr[row][mid]>=left && arr[row][mid]>=right)
    {
        return {row,mid};
    }
    else if (arr[row][mid]<left) //peak element on the left eg 6,4  4<6 -decreasing slope
        high=mid-1;
    else
        low=mid+1;
}
return {-1,-1};
}


int main()
{
vector<vector<int>> arr={{4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2}};
int n=arr.size();
int m=arr[0].size();
vector<int> output=peakelementin2darray(arr,n,m);
cout << "Peak element found at index: " << output[0]
         << ", " << output[1] << endl;
return 0;
}

