#include<bits/stdc++.h>
using namespace std;



//brute force- using 2 for loops and  counting the no of occurences
// int elementappearsonce(int arr[],int n)
// {
//     int count;

//     for(int i=0;i<n;i++)
//     {
//         count=0;
//         for(int j=0;j<n;j++)
//         {
//             if (arr[i]==arr[j])
//             {
//                 count=count+1;
//             }
//         }
//         if (count==1)
//         {
//             return arr[i];
//         }
//     }
//     return 0;
// }


//better solution -using hashing
// int elementappearsonce(int arr[],int n)
// {
//     int maxi=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         maxi=max(maxi,arr[i]);
//     }
//     cout<<maxi<<endl;
//     int hash[maxi+1]={0};
//     for(int i=0;i<n;i++)
//     {
//         hash[arr[i]]++;
//     }    
//     for(int i=1;i<n;i++)
//     {
//         if (hash[arr[i]]==1)
//         {
//         return arr[i];
//         }
//     }
//     return 0;
// }

//better solution using mapping

// int elementappearsonce(int arr[],int n)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }
//    for(auto it:mpp)
//    {
//     if (it.second==1)
//     {
//         return it.first;
//     }
//    }
//    return 0;

// }




//optimal solution -using xor

int elementappearsonce(int arr[],int n)
{
    int xor1=0;
    for(int i=0;i<n;i++)
    {
        xor1=xor1^arr[i];
    }
    return xor1;
}
int main()
{
    int arr[]={1,1,2,3,3,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=elementappearsonce(arr,n);
    cout<<result<<endl;
    return 0;
}