#include<bits/stdc++.h>
using namespace std;


// pair<int,int> firstlastoccurence(vector<int>& arr,int n,int x)
// {
//     int first=n;
//     int last=0;
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]==x)
//         {
//             first=min(first,i);
//             last=max(last,i);
//         }
//     }
//     return {first,last};
// }


// -------------------------------------------------------------------------------------------------------------------------------------------------
// pair<int,int> firstlastoccurence(vector<int>& arr,int n,int x)
// {
//     int first=-1;
//     int last=-1;
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]==x)
//         {
//             if (first==-1){
//             first=i;
//             last=i;
//             }
//             else{
//                 last=i;
//             }
//         }
//     }
//     return {first,last};
// }
// -------------------------------------------------------------------------------------------------------------------------------------------------
// int firstocc(vector<int>& arr,int n,int x)
// {
//     int low=0;
//     int high=n-1;
//     int ans=-1;
// while(low<=high)
// {
//     int mid=(low+high)/2;
//     if (arr[mid]==x)
//     {
//         ans=mid;
//         high=mid-1;

//     }
//     else if (arr[mid]>x)
//     {
//         high=mid-1;
//     }
//     else
//     {
//         low=mid+1;
//     }
// }
// return ans;
// }
// int lastocc(vector<int>& arr,int n,int x)
// {
//     int low=0;
//     int high=n-1;
//     int ans=-1;
// while(low<=high)
// {
//     int mid=(low+high)/2;
//     if (arr[mid]==x)
//     {
//         ans=mid;
//         low=mid+1;

//     }
//     else if (arr[mid]>x)
//     {
//         high=mid-1;
//     }
//     else
//     {
//         low=mid+1;
//     }
// }
// return ans;
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
int firstocc(vector<int>& arr,int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int lastocc(vector<int>& arr,int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
pair<int,int> firstlastoccurence(vector<int>& arr,int n,int x)
{
    int first=firstocc(arr,n,x);
    int last=lastocc(arr,n,x);
    if (first==n || arr[first]!=x)
    {
        return {-1,-1};
    }
    return {first,last-1};
}

int main()
{
    vector<int> arr={2,4,5,6,8,8,8,11,13};
    int n=arr.size();
    int x=8;
    pair<int,int> result=firstlastoccurence(arr,n,x);
    cout<<"first:"<<result.first<<"\n"<<"last"<<" "<<result.second;
    return 0;
}