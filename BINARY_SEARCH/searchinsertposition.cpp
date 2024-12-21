#include<bits/stdc++.h>
using namespace std;



int searchposition(vector<int>& arr,int n,int target)
{
    int low=0,high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if (arr[mid]>target)
        {
            // ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return high+1;
}


int main()
{
    // vector<int> arr={1,2,4,7};
        vector<int> arr={1,3,5,7,8,12};

    int target=6;
    int result=searchposition(arr,arr.size(),target);
    cout<<result<<endl;
    return 0;
}