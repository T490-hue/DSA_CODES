#include<bits/stdc++.h>
using namespace std;





// int noofsubarrayswithxorask(vector<int> arr,int n,int k)
// {
//     int count=0;
//     int xr;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             xr=0;
//             for(int k=i;k<=j;k++)
//             {
//                 xr=xr^arr[k];
//             }
//             if (xr==k)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }


int noofsubarrayswithxorask(vector<int> arr,int n,int k)
{
    int count=0;
    int xr;
    for(int i=0;i<n;i++)
    {
        xr=0;
        for(int j=i;j<n;j++)
        {
            xr=xr^arr[j];
            
            if (xr==k)
            {
                count++;
            }
        }
    }
    return count;
}

// int noofsubarrayswithxorask(vector<int> arr,int n,int k)
// {
//     int xr=0;
//     map<int,int> mpp;
//     mpp[xr]++;
//     int count=0;
//     for(int i=0;i<n;i++)
//     {
//         xr=xr^arr[i];
//         int x=xr^k;
//         count+=mpp[x];
//         mpp[xr]++;
//     }
//     return count;
// }
int main()

{
    vector<int> arr={4, 2, 2, 6, 4};
    int n=arr.size();
    int k=6;
    int ans=noofsubarrayswithxorask(arr,n,k);
    cout<<ans<<" ";
    return 0;
}