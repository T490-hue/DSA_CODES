#include<bits/stdc++.h>
using namespace std;


int indexofrotation(vector<int>& arr,int n)
{
    int low=0;
    int high=n-1;
    int index=-1;
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[low]<=arr[high])
        {
            if (ans>arr[low])
            {
                ans=arr[low];
                index=low;
            }
        }
        if (arr[low]<=arr[mid])//left sorted
        {
            if (ans>arr[low])
            {
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else
        {
            if (ans>arr[mid])
            {
                ans=arr[mid];
                index=mid;
            }
            high=mid-1;
        }

    }
    return index;
}

int main()
{
    // vector<int> arr={4,4,4,4,0,1,2,3,4};
    vector<int> arr={7,8,9,0,1,2,3,7};

    int n=arr.size();
    int result=indexofrotation(arr,n);
    cout<<result;
    return 0;
}