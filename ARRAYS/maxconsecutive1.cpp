#include<bits/stdc++.h>
using namespace std;


int maxnoofconsecutive1(int arr[],int n)
{
    int maxi,count=0;
    for(int i=0;i<n;i++)
{
    if (arr[i]==1)
    {
        count+=1;
        maxi=max(maxi,count);
    }
    else{
        count=0;
    }
}
return maxi;
}

int main()
{
    int a[]={1,1,0,1,1,1,1,0,0,1,1};
    int n=sizeof(a)/sizeof(a[0]);
    int result=maxnoofconsecutive1(a,n);
    cout<<result;
    return 0;
}