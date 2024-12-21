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
int canweplace(vector<int>& arr,int distance,int cows)
{
    int n=arr.size();
    int cntcows=1;
    int last=arr[0]; //1st cow is placed at the first position
    for(int i=0;i<n;i++)
    {
        if (arr[i]-last >=distance)
        {
            cntcows++; //place the next cows there
            last=arr[i];
        }
        if (cntcows>=cows) return 1;
    }
     return 0;
}

// int maxdistance(vector<int>& arr,int cows)
// {
//     sort(arr.begin(), arr.end()); 
//     int maxi=calculatemaximum(arr);
//     int mini=calculateminimum(arr);
//     int low=mini;
//     int high=maxi;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;
    
//         if (canweplace(arr,mid,cows)==1)
//         {
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }
//     }
//     return high;
// }

int maxdistance(vector<int>& arr,int cows)
{
    sort(arr.begin(), arr.end()); 
    int maxi=calculatemaximum(arr);
    int mini=calculateminimum(arr);
    for(int i=1;i<=maxi-mini;i++)    
        if (canweplace(arr,i,cows)==1)
        {
            continue;
        }
        else
        {
            return (i-1);
        }
    
    return 0;
}


int main()
{
    vector<int> arr={0,3,4,7,9,10};
    int cows=4;
    int maxdist=maxdistance(arr,cows);
    cout<<maxdist;
    return 0;
}