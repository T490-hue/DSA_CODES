#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestsubarray(int a[],int n,int l)
{
    int maxi=0;
    int sum;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum=0;

            for(int k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if (sum==l)
            {
                maxi=max(maxi,j-i+1);
            }
        }

    }
    return maxi;
}




// int longestsubarray(int a[],int n,int l)
// {
//     int maxi=0;
//     int sum;
//     for(int i=0;i<n;i++)
//     {
//     sum=0;
//    for(int j=0;j<n;j++)
//    {
//     sum+=a[j];
//     if(sum==l)
//     {
//         maxi=max(maxi,j-i+1);
//     }

//    }
//    }
//    return maxi+1;
// }





// int longestsubarray(int a[],int n,int l)
// {
//     long long sum=0;
//     map <long long,int> mpp;
//     int maxi=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=a[i];
//         if(sum==l)
//         {
//             maxi=max(maxi,i+1);
//         }
//         int rem=sum-l;
//         if (mpp.find(rem)!=mpp.end())
//         {
//             int val=i-mpp[rem];
//             maxi=max(maxi,val);
//         }
//         if (mpp.find(rem)==mpp.end())
//         {
//             mpp[sum]=i;
//         }

//     }
//     return maxi;
//  }

// int longestsubarray(int arr[],int n,int l)
// {
//   int s=arr[0];
//     int maxi=0;
//     int left=0;
//     int right=0;
//     while(right<n)
//     {
//         while( left<=right && s>l)
//         {
//             s-=arr[left];
//             left++;
//         }
//         if (s==l)
//         {
//             maxi=max(maxi,right-left+1);
//         }
//         right++;
//         if (right<n)
//         {
//             s+=arr[right];
//         }
//     }
//     return maxi;
// }


int main()
{
    int arr[]={1,2,3,1,1,1,1,4,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=6;
    int result=longestsubarray(arr,n,l);
    cout<<result<<endl;
    return 0;
}