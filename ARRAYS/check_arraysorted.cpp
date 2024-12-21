#include<iostream>
using namespace std;

int isSorted(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if (arr[i-1]<arr[i])
        continue;
        else
        return -1;
    }
    return 1;
}

int main()
{
    int arr[]={2,4,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=isSorted(arr,n);
    if (result !=-1)
    {
        cout<<" array is sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}