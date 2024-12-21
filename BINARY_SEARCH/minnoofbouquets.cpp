#include<bits/stdc++.h>
#include<climits>
using namespace std;


// int calculateminimum(vector<int>& arr)
// {
//     int n=arr.size();
//     int mini=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         mini=min(mini,arr[i]);
//     }
//     return mini;
// }

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
// int possible(vector<int>& arr,int day,int k,int m)
// {
//     int n=arr.size();
//     int cnt=0;
//     int no_bouquet=0;
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]<=day)
//             cnt++;
//         else{
//             no_bouquet+=(cnt/k);
//             cnt=0;
//     }}
//        no_bouquet+=(cnt/k);
//        return no_bouquet >= m;
// }
// int noofdays(vector<int>& arr,int k,int m)
// {
//     int n=arr.size();
//     int mini=calculateminimum(arr);
//     int maxi=calculatemaximum(arr);
//     for(int day=mini;day<=maxi;day++)
//     {
//         if (possible(arr,day,k,m)==1)
//             return day;
//     }
//             return -1;
// }



int calculateminimum(vector<int>& arr)
{
    int n=arr.size();
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mini=min(mini,arr[i]);
    }
    return mini;
}

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
int possible(vector<int>& arr,int day,int k,int m)
{
    int n=arr.size();
    int cnt=0;
    int no_bouquet=0;
    for(int i=0;i<n;i++)
    {
        if (arr[i]<=day)
            cnt++;
        else{
            no_bouquet+=(cnt/k);
            cnt=0;
    }}
       no_bouquet+=(cnt/k);
       if (no_bouquet==m) return 1;
       else if (no_bouquet<m) return 2;
       else return 0;
}
int noofdays(vector<int>& arr,int k,int m)
{
    int n=arr.size();
    int mini=calculateminimum(arr);
    int maxi=calculatemaximum(arr);
    int low=mini;
    int high=maxi;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (possible(arr,mid,k,m)==1)
            return mid;
        else if (possible(arr,mid,k,m)==2)
            low=mid+1;
        else
            high=mid-1;
    }   
    return -1;
}

int main()
{
    vector<int> arr={7,7,7,7,13,11,12,7};
    // vector<int> arr={1,10,3,10,2};
    int n=arr.size();
    // int k=3;    
    int k=2;

    // int m=2;   
      int m=3;

    int minofdays=noofdays(arr,k,m);
    cout<<minofdays;
    return 0;
}
