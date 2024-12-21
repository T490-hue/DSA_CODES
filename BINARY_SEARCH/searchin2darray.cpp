#include<bits/stdc++.h>
using namespace std;

// int search(vector<vector<int>>& arr,int n,int m,int target)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if (arr[i][j]==target)
//                 return true;
//         }
//     }
//     return false;
// }
// -----------------------------------------------------------------------------------------------------------------------------------------------------------
// int binarysearch(vector<int>& arr,int m,int target)
// {
//     int n=arr.size();
//     int low=0;
//     int high=m-1;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==target)
//             return mid;
//         else if (arr[mid]<target)
//             low=mid+1;
//         else
//             high=mid-1;
//     }
//     return -1;
// }

// int search(vector<vector<int>>& arr,int n,int m,int target)
// {
//     for(int i=0;i<n;i++)
//     {
//         int found=binarysearch(arr[i], m,target);

//         if (found!=-1)
//         return true;
//     }
//     return false;
// }
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool search(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 15}, {9, 10, 11, 12}};
    search(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------
// int search(vector<vector<int>>& arr,int n,int m,int target)
// {
//     int low=0;
//     int high=(n*m)-1;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         int row=mid/m;
//         int col=mid%m;
//         if (arr[row][col]==target)
//             return true;
//         else if (arr[row][col]<target)
//             low=mid+1;
//         else
//             high=mid-1;
//     }
//     return false;
// }
// int main()
// {
//     vector<vector<int>> arr={{3,4,7,9},{12,13,16,18},{20,21,24,29}};
//     int n=arr.size();
//     int m=arr[0].size();
//     int target=23;
//     int found=search(arr,n,m,target);
//     cout<<found;
//     return 0;
// }