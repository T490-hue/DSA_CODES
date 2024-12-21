#include<bits/stdc++.h>
using namespace std;


int lower_bound(vector<int> arr,int x)
{
    int low=0;
    int high=arr.size()-1;
    int ans=0;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }


    }
    return ans;
}
int main()
{
    vector<int> arr={1,2,3,3,5,8,8,9,10,10,11};
    int val=lower_bound(arr,9);
    cout<<val;
    return 0;
}