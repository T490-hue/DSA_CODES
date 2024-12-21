#include<bits/stdc++.h>
using namespace std;

// int maxProductSubArray(vector<int>& nums) {
//     int result = INT_MIN;
//     for(int i=0;i<nums.size()-1;i++) {
//         for(int j=i+1;j<nums.size();j++) {
//             int prod = 1;
//             for(int k=i;k<=j;k++) 
//                 prod *= nums[k];
//             result = max(result,prod);    
//         }
//     }
//     return result;
// }





//better approach
// int maxProductSubArray(vector<int>& nums) {
//     int result = INT_MIN;
//     for(int i=0;i<nums.size()-1;i++) {
//         int prod = 1;

//         for(int j=i+1;j<nums.size();j++) {
//             prod *= nums[j];
//             result = max(result,prod);    
//         }
//     }
//     return result;
// }

//optimal approach

 int maxProductSubArray(vector<int>& arr) {
    int maxi=INT_MIN;
    int prefix=1,suffix=1;
    int n=arr.size();
    for(int i=0;i<n;i++)
{
    if (prefix==0)
    {
        prefix=1;
    }
    if(suffix==0){
        suffix=1;
    }
    prefix*=arr[i];
    suffix*= arr[n - i - 1];
    maxi=max(maxi,max(prefix,suffix));
}
return maxi;
 }

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
