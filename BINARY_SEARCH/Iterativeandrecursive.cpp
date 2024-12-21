#include<bits/stdc++.h>
using namespace std;


// int binary_search(vector<int> arr,int target,int n)
// {
//     int low=0,high=n-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==target)
//         {
//             return mid;
//         }
//         else if (arr[mid]>target)
//         {
//             high=mid-1;
//         }
//         else
//         {
//             low=mid+1;
//         }
//     }
//     return -1;
// }


int recurse_binary(vector<int>& arr,int low,int high,int target)
{
if (low>high)
{
    return -1;
}
int mid=(low+high)/2;
if (arr[mid]==target)
return mid;
else if (arr[mid]>target)
return recurse_binary(arr,low,mid-1,target);
else
return recurse_binary(arr,mid+1,high,target);
}

int binary_search(vector<int>& arr,int target,int n)
{
    int result=recurse_binary(arr,0,n-1,target);
}
int main()
{
    vector<int> arr={3, 4, 6, 7, 9, 12, 16, 17};
    int target=6;
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