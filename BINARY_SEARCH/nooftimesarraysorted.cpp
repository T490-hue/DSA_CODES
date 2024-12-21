#include<bits/stdc++.h>
using namespace std;

int minelement(vector<int> arr,int n)
{
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[low]<=arr[high])//both left half and right half is sorted
        {
            if (ans>arr[low])
            {
                ans=arr[low];
                index=low;
            }
            // break; for duplicates 
        }
        if (arr[low]<=arr[mid])//left half is sorted
        {
              if (ans>arr[low])
            {
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else//right half is sorted
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
    // vector<int> rotated={7,8,0,2,3,4,5,6};
    vector<int> rotated={4, 5, 6, 7, 0, 1, 2, 3,4,4};;

    int n=rotated.size();
    int element=minelement(rotated,n);
    cout<<element<<endl;
    return 0;
}