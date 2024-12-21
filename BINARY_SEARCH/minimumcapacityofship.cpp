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

// int calculatedays(vector<int>& arr,int capacity)
// {
//     int n=arr.size();
//     int days=1;
//     int load=0;
//     for(int i=0;i<n;i++)
//     {
//         if (load+arr[i]>capacity)
//         {
//             load=arr[i];
//             days+=1;
//         }
//         else
//         {
//             load+=arr[i];
//         }
//     }
//     return days;
// }
// int mincap(vector<int>& arr,int days)
// {
//     int n=arr.size();
//     int mini=calculatemaximum(arr);
//     int maxi=(mini*(mini+1))/2;
//     for(int capacity=mini;capacity<=maxi;capacity++)
//     {
//         int daysreq=calculatedays(arr,capacity);
//         if (daysreq<=days)
//         {
//             return capacity;
//         }
//     }
//     return -1;
// }



    bool ispossible(vector<int>& weights, int days,int minimum_capacity)
    {
        long long load=0;
        int day=1;
        for(int i=0;i<weights.size();i++)
        {
            if (load+weights[i]<=minimum_capacity)
            {
                load+=weights[i];
            }
            else
            {
                load=weights[i];
                day++;
                if (day > days) return false; 
            }
        }
        return day<=days;
    }
    pair<int,int> maxmin(vector<int>& weights)
    {
        int n=weights.size();
        int mini=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini=max(mini,weights[i]);
        }
        long long maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi+=weights[i];
        }
        return {mini,maxi};
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int mini=maxmin(weights).first;
        int maxi=maxmin(weights).second;
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if (ispossible(weights,days,mid))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }


int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    int minimumcapacity=shipWithinDays(arr,days);
    cout<<minimumcapacity;
    return 0;
}