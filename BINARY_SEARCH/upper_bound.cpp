// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int  binary_search(vector<int> arr,int target,int n)
// {
//     int low=0,high=n-1;
//     int ans=n;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]>target)
//         {
//             ans=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//         }
// return ans;
// }


int main()
{
    vector<int> arr={2, 3, 7, 8,9, 12, 16, 17};
    int target=8;
    int n=arr.size();
    int result=binary_search(arr,target,n);

    if (result !=-1)
    {
        cout<<"element found at :"<<result+1;

    }
    else{
        cout<<"element not found";
    }
    return 0;
}