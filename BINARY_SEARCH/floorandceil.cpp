#include<bits/stdc++.h>
using namespace std;


// int findfloor(vector<int>& arr,int n,int target)//find the largest element which is less than or equal to x
// {
//     int ans=-1;
//     int low=0;
//     int high=n-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]<=target)
//         {
//             ans=arr[mid];
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }
//     }
//     return ans;

// }
// int findceil(vector<int>& arr,int n,int target)//find the smallest no which is >=x
// {
//     int ans=-1;
//     int low=0;
//     int high=n-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]>=target)
//         {
//             ans=arr[mid];
//             high=mid-1;
//         }
//         else
//         {
//             low=mid+1;
//         }
//     }
//     return ans;
// }




// pair<int,int> floorandceil(vector<int>& arr,int n,int target)
// {
//     int floor=findfloor(arr,n,target);
//     int ceil=findceil(arr,n,target);
// return {floor,ceil};
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------



// pair<int,int> floorandceil(vector<int>& arr,int n,int target)
// {
//     int low=0;
//     int high=n-1;
//     int floor=-1;                                            
//     int ceil=-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==target)
//         {
//             floor=arr[mid];
//             ceil=arr[mid];
//             break;
//         }
//         else if (arr[mid]>target)
//         {
//             floor=arr[mid-1];
//             ceil=arr[mid];
//             high=mid-1;
//         }
//         else
//         {
//             low=mid+1;
//         }
//     }
//     return {floor,ceil};
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------
pair<int,int> floorandceil(vector<int>& arr,int n,int target)
{
    int floor=-1,ceil=-1;
    for(int i=0;i<n;i++)
    {
        if (arr[i]<=target) //floor
        {
            floor=arr[i];
        }
        if (arr[i]>=target)
        {
            ceil=arr[i];
            if(ceil!=-1)
            break;
        }
    }
    return {floor,ceil};
}


int main() {
	vector<int> arr = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = floorandceil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}