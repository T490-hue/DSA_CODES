#include<bits/stdc++.h>
using namespace std;
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

int calstudents(vector<int>& arr,int pages)
{
    int cntsnt=1;
    int pages_st=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if (pages_st+arr[i]<=pages)
            pages_st+=arr[i];
        else
        {
            cntsnt++;
            pages_st=arr[i];
        }
    }
    return cntsnt;
}

// int maximumnoofpages(vector<int>& arr,int m)
// {
//     int maxi=calculatemaximum(arr);
//     int summation=maxi*(maxi+1)/2;
//     for(int pages=maxi;pages<=summation;pages++)
//     {
//         if (calstudents(arr,pages)==m)
//             return pages;
//     }
//     return 0;
// }

int maximumnoofpages(vector<int>& arr,int m)
{
    int maxi=calculatemaximum(arr);
    int summation=maxi*(maxi+1)/2;
    int low=maxi;
    int high=summation;
    while (low<=high)
    {
        int mid=(low+high)/2;
        
        if (calstudents(arr,mid)<=m)
       
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}


int main()
{
    vector<int> arr={25,46,28,49,24};
    int m=4;
    int maximum=maximumnoofpages(arr,m);
    cout<<maximum;
    return 0;
}