#include<bits/stdc++.h>
using namespace std;
//brute approach-linear search



//better approach-binary search -find the sorted array ,pick the min element and elimimate that half
// int minelement(vector<int> arr,int n)
// {
//     int low=0;
//     int high=n-1;
//     int ans=INT_MAX;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[low]<=arr[mid])//left half is sorted
//         {
//             ans=min(ans,arr[low]);
//             low=mid+1;
//         }
//         else//right half is sorted
//         {
//             ans=min(ans,arr[mid]);//as in the right half the mid element will be the minimal;
//             high=mid-1;
//         }
//     }
//     return ans;
// }



//optimal solution 


// int minelement(vector<int> arr,int n)
// {
//     int low=0;
//     int high=n-1;
//     int ans=INT_MAX;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[low]<=arr[high])//both left hal;f and right half is sorted
//         {
//             ans=min(arr[low],ans);
//             break;
//         }
//         if (arr[low]<=arr[mid])//left half is sorted
//         {
//             ans=min(ans,arr[low]);
//             low=mid+1;
//         }
//         else//right half is sorted
//         {
//             ans=min(ans,arr[mid]);//as in the right half the mid element will be the minimal;
//             high=mid-1;
//         }
//     }
//     return ans;
// }


//what if duplicates are there

   int minelement(vector<int>& nums,int n) {
                int low = 0, high=n- 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high)/ 2;

            if (nums[low] == nums[mid] &&  nums[mid] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            if (nums[low]<=nums[high])
            {
                ans=min(ans,nums[low]);
                low++;
            }
             if (nums[mid] >= nums[low]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else { 
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
}

int main()
{
    // vector<int> rotated={7,8,0,2,3,4,5,6};
    vector<int> rotated={3,2,1,3,3,3,3,3};

    int n=rotated.size();
    int element=minelement(rotated,n);
    cout<<element<<endl;
    return 0;
}