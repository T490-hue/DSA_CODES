#include<bits/stdc++.h>
using namespace std;


int singleelement(vector<int>& arr,int n)
{
    if (arr[0]!=arr[1]) return arr[0];
    if (arr[n-1]!=arr[n-2]) return arr[n-1];
    for(int i=1;i<n-1;i++)
    {
        if (arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
        return arr[i];
    }
    return -1;
}

// int singleelement(vector<int>& arr,int n)
// {
//     if (n==1)
//     return arr[0];

//     if (arr[0]!=arr[1]) return arr[0];
//     if (arr[n-1]!=arr[n-2]) return arr[n-1];

//     int low=1;
//     int high=n-1;
//     while (low<=high)
//     {
//         int mid =(low+high)/2;

//         if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
//         return arr[mid];

//         else if ((mid%2==1) && arr[mid]==arr[mid-1] || (mid%2==0) && arr[mid]==arr[mid+1])
//         low=mid+1;

//         else
//         high=mid-1;
//     }
//     return -1;
// }



int main()
{
    vector<int> duplicates={1,1,2,2,3,3,4,5,5,6,6};
    int n=duplicates.size();
    int value=singleelement(duplicates,n);
    cout<<value;
    return 0;
}