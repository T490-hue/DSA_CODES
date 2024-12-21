#include<bits/stdc++.h>
using namespace std;


// int calculatemaximum(vector<int>& arr)
// {
//     int n=arr.size();
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         maxi=max(maxi,arr[i]);
//     }
//     return maxi;
// }

// int ispossible(vector<int>& arr,int divisor,int threshold)
// {
//     int n=arr.size();
//     int total=0;
//     for(int i=0;i<n;i++)
//     {
//         total+=ceil(double(arr[i])/double(divisor));
//     }
//     if (total<=threshold) return 1;
//     else 
//     return 0;
// }

// int smallestdivisor(vector<int>& arr,int threshold)
// {
//     int n=arr.size();
//     int maxi=calculatemaximum(arr);
//    
//     for(int divisor=1;divisor<=maxi;divisor++)
//     {
//         if(ispossible(arr,divisor,threshold)==1)
//             return divisor;
//     }
//     return 0;
// }



int calculatemaximum(vector<int>& arr)
{
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int ispossible(vector<int>& arr,int divisor,int threshold)
{
    int n=arr.size();
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=ceil(double(arr[i])/double(divisor));
    }
    if (total<=threshold) return 1;
    else 
    return 0;
}

int smallestdivisor(vector<int>& arr,int threshold)
{
    int n=arr.size();
    int maxi=calculatemaximum(arr);
    int low=1;
    int high=maxi;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (ispossible(arr,mid,threshold)==1)
            high=mid-1; // find the smallest divisor
        else 
            low=mid+1;
    }
    return low;
}


int main()
{
    vector<int> arr={1,2,5,9};
    // vector<int> arr={1,2,3,4,5};

    int n=arr.size();
    int threshold=6;
    // int threshold=8;

    int smallest=smallestdivisor(arr,threshold);
    cout<<"divisor:"<<smallest;
    return 0;
}