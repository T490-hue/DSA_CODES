#include<bits/stdc++.h>
using namespace std;

// int missingnumber(int a[],int n)

// {
//     int hash[n+1]={0};
//     for(int i=0;i<n;i++)
//     {
//         hash[a[i]]=1;
//     }
//     for(int i=1;i<=n+1;i++)
//    {
//     if (hash[i]==0)
//     {
//         return i;
//     }
//    }
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// int missingnumber(int a[],int n)
//  {
//     int N=n+1;
//     int sum1=N*(N+1)/2;
//     int s2=0;
//     for(int i=0;i<n;i++)
//     {
//         s2+=a[i];
//     }
//     return (sum1-s2);
//  }
// -------------------------------------------------------------------------------------------------------------------------------------------------------------
// int missingnumber(int arr[],int n)
// {
  
// int maxi=-1;
// for(int i=0;i<n;i++)
// {
//     maxi=max(maxi,arr[i]);
// }
// for(int i=1;i<=maxi;i++)
// {
//     bool found=false;
//     for(int j=0;j<n;j++)
//     {
//         if (arr[j]==i)
//         {
//             found=true;
//             break;
//         }
//     }
//     if (!found)
//     {
//         return i;
//     }
// }
// return 0;
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------


int missingnumber(vector<int> arr,int n,int k)
{
    unordered_set<int> st(arr.begin(),arr.end());
    for(int i=1;i<=k;i++)
    {
        if (st.find(i)==st.end())
    {
        return i;
    }
}
return 0;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------



//using XOR
// int missingnumber(int arr[],int n)
// {
//     int XOR1=0,XOR2=0;
//     int N=n+1;
//     for(int i=0;i<n;i++)
//     {
//         XOR1=XOR1^arr[i];   //1^2^4^5=1
//         XOR2=XOR2^(i+1);   //1^2^3^4^5=2
//     }
//     XOR2=XOR2^N;
//     return XOR1^XOR2;
// }
int main()
{
    vector<int> a={1,2,4,5};
    int n=a.size();
    int k=5;
    int result=missingnumber(a,n,k);
    cout<<result<<endl;
    return 0;
}