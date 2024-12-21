#include<bits/stdc++.h>
using namespace std;


int caltime(vector<int>& arr,int hourly)
{
    int time=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
       time+=ceil(double(arr[i])/double(hourly)); 
    }
    return time;
}
// int kokoeatingbanana(vector<int>& arr,int h)
// {
//     int n=arr.size();
//     int maxi=0;
//     for (int i=0;i<n;i++)
//     {
//         maxi=max(maxi,arr[i]);
//     }
//     for (int i=1;i<=maxi;i++)
//     {
//     int reqtime=caltime(arr,i);
//     if (reqtime<=h)
//     {
//         return i;
//     }
//     }
//     return 0;
// }



//optimal approach is using binary seacrgh
int kokoeatingbanana(vector<int>& arr,int hours)
{
    int n=arr.size();
    int maxi=0;
    for (int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    int low=1;
    int high=maxi;
    while (low<=high){
    
    int mid=(low+high)/2;
    int reqtime=caltime(arr,mid);
    if (reqtime<=hours)
        high=mid-1;
    else
        low=mid+1;
    }
    return low;
}

int main()
{
    vector<int> arr={3,6,7,11};
    int h=8;
    int kokoeating=kokoeatingbanana(arr,h);
    cout<<"no of bananas that the koko should have in one hour to complete eating everything in 8 hrs:"<<"   "<<kokoeating<<" ";
    return 0;
}