#include<bits/stdc++.h>
using namespace std;

bool indexofelement(vector<int> arr,int n,int target)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if (arr[mid]==target)
        {
            return true;
        }

        if (arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low=low+1;
            high=high-1;
            continue;
        }
        //check if its left or right sorted
        else if (arr[low]<=arr[mid])         //left sorted
        {
            if (arr[low]<=target && arr[mid]>=target) // the element is in the left half so eliminate the right half
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else // the right half is sorted
        {
            if (arr[mid]<=target && arr[high]>=target)// the element is in the right half so eliminate the left half
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;//if its not in the right half ,eleminate the right half
            }
        }
    }
    return false;
}

int main()
{
    vector<int> rotated={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n=rotated.size();
    bool index=indexofelement(rotated,n,3);
    cout<<index<<" ";
    return 0;
}