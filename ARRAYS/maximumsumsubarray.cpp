#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;


// int longesumtsumubarray(int a[],int n,int l)
// {
//     int maxi=0;
//     int sum;
//     for(int i=0;i<n;i++)
//     {
//         sum=0;
//         for(int j=0;j<n;j++)
//         {
//             for(int k=i;k<j;k++)
//             {
//                 sum+=a[k];
//             }
//             if (sum==l)
//             {
//                 maxi=max(maxi,j-i+1);
//             }
//         }

//     }
//     return maxi;
// }




// int longesumtsumubarray(int a[],int n,int l)
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



//optimal solution -kadane algorithm 


// int maximumsum(vector<int> arr,int n)
// {
//     int sum=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];

//         if (sum>maxi)
//         {
//             maxi=sum;
//         }
//         if (sum<0)
//         {
//             sum=0;
//         }
        

        
//     }
//     return maxi;
// }


//to return the subarray with maximum sum
vector<int> maximumsum(vector<int> arr,int n){
    int sum=0,maxi=INT_MIN;
    int ansstart=-1,ansend=-1;
    int start=0;
    for(int i=0;i<n;i++)
    {
        if (sum==0)
        {
            start=i;

        }
        sum+=arr[i];

        if (sum>maxi)
        {
            maxi=sum;
            ansstart=start;
            ansend=i;
        }
        if (sum<0)
        {
            sum=0;
        }
    }
    return {ansstart,ansend} ;
}

int main()
{
vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
int n=arr.size();
vector<int> result=maximumsum(arr,n);
for (int i:result){
cout<<i<<endl;
}
return 0;
}

