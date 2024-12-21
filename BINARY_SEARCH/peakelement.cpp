#include<bits/stdc++.h>
using namespace std;


// vector<int> peakelement(vector<int>& arr,int n)
// {
//     vector<int> temp;
//     for(int i=0;i<n;i++)
//     {
//         if (i==0 && arr[i]>arr[i+1])
        
//             temp.push_back(arr[i]);
        
//         if (i==n-1 && arr[i]>arr[i-1])

//             temp.push_back(arr[i]);
        
//         if (arr[i]>arr[i+1] && arr[i]>arr[i-1])
//             temp.push_back(arr[i]);
//     }
//     return temp;
// }
 


//optimised approach using binary search

int peakelement(vector<int>& arr,int n)
{
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    int low=1;
    int high=n-2;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return arr[mid];
        else if (arr[mid]>arr[mid-1] || arr[mid+1]>arr[mid]) //mid is in the increasing half
            low=mid+1;
        else 
            high=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> a={1,2,3,4,5,6,7,8,5,1};
    // vector<int> a={1,2,1,3,5,6,4};

    int n=a.size();
    int element=peakelement(a,n);

    cout<<element<<" ";
    
    return 0;
}