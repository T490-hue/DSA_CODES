#include<bits/stdc++.h>
using namespace std;



//brute approach
// vector<int> findMissingRepeatingNumbers(vector<int> arr)
// {
//     int n=arr.size();
//     int cnt;
//     int repeating=-1,missing =-1;
//     for(int i=1;i<=n;i++) //checking from numbers 1 to 6 which are missing
//     {
//         cnt=0;
//         for(int j=0;j<n;j++)
//         {
//             if (arr[j]==i)
//             cnt++;
//         }
//         if (cnt==0)
//         missing=i;
//         else if (cnt==2)
//         repeating=i;

//         if (repeating!=-1 && missing !=-1)
//         break;
//     }
//     return {repeating,missing};
// }

//better approach-suing hashing

// vector<int> findMissingRepeatingNumbers(vector<int> arr)
// {
//     int n=arr.size();
//     int hash[n+1]={0};
//     int repeating=-1,missing=-1;
//     for(int i=0;i<n;i++)
//     {
//       hash[arr[i]]++;  
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if (hash[i]==2)
//         repeating=i;
//         else if (hash[i]==0)
//         missing=i;
//     }
//     return {repeating,missing};
// }


//optimal approach

// vector<int> findMissingRepeatingNumbers(vector<int> arr)
// {
//     int n=arr.size();
//     int SN=(n*(n+1))/2;
//     int S2N=(n*(n+1)*(2*n+1))/6;
//     int S=0,S2=0;
//     for(int i=0;i<n;i++)
//     {
//         S+=arr[i];
//         S2+=arr[i]*arr[i];
//     }
//     int val1=S-SN;//(X-Y)
//     int val2=S2-S2N;//(X^2-Y^2)
//     val2=val2/val1;//X+Y
//     int X=(val2+val1)/2;
//     int Y=X-val1;
// return {X,Y};

// }


//optimal approach 2

vector<int> findMissingRepeatingNumbers(vector<int> arr)
{
    int xr=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int bitno=0;
    while(1)
    {
        if ((xr & (1<<bitno))!=0) //left shift 1 by the no of positions determined by  bitno 
        {
            break;
        }
        bitno++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        if ((arr[i] & (1<<bitno))!=0)
        {
            one=one^arr[i];
        }
        else
        {
            zero=zero^arr[i];
        }
    }
        for(int i=1;i<=n;i++)
    {
        if ((i & (1<<bitno))!=0)
        {
            one=one^i;
        }
        else
        {
            zero=zero^i;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if (arr[i]==zero)
        cnt++;
    }
    if (cnt==2){
        return {zero,one};
    }
    else{
        return {one,zero};
    }

}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}