#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------------------------------------------------------------------------------------------------------------
//brute
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
// int isfound(vector<int>& arr,int number)
// {
// bool isfoundnumber=false;
// int n=arr.size();
// for(int i=0;i<n;i++)
// {
//     if (arr[i]==number)
//         isfoundnumber=true;
// }
// if (isfoundnumber==true)
// return 1;
// else
// return 0;
// }
// int kthmissingnumber(vector<int>& arr,int k)
// {
//     int n=arr.size();
//     vector<int> temp;
//     int maxi=calculatemaximum(arr);
//     for(int i=1;i<=maxi;i++)
//     {
//        if (isfound(arr,i)==0)
//         temp.push_back(i);
//     }

// return temp[k-1];
// }


// --------------------------------------------------------------------------------------------------------------------------------------------------------
// brute with O(n)
// int kthmissingnumber(vector<int>& arr,int k)
// {
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]<=k) k++;
//         else break;
//     }
//     return k;
// }



//optimal approach
int kthmissingnumber(vector<int>& arr,int k)
{
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int missing=arr[mid] - (mid + 1);
        if (missing <k)
            low=mid+1;
        else
            high=mid-1;
    }
    return (high+1+k);

}


int main()
{
    // vector<int> arr={2,3,4,7,11};
        vector<int> arr={5,7,10,12};

    // int k=3;
        int k=4;

    int kthmissing=kthmissingnumber(arr,k);
    cout<<kthmissing;
    return 0;
}