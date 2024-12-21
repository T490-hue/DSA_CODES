// #include <bits/stdc++.h>
// using namespace std;

// void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
//     if (index == nums.size()) {
//         ans.push_back(nums);
//         return;
//     }
//     for (int i = index; i < nums.size(); i++) {
//         swap(nums[index], nums[i]);
//         recurPermute(index + 1, nums, ans);
//         swap(nums[index], nums[i]); // Backtrack
//     }
// }

// vector<int> findNext(const vector<vector<int>>& ans, const vector<int>& next) {
//     for (int i = 0; i < ans.size(); i++) {
//         if (ans[i] == next) {
            
//             return ans[(i + 1) % ans.size()];
//         }
//     }
//     return {};
// }

// int main() {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> ans;
//     vector<int> next = {3, 1, 2};

//     recurPermute(0, nums, ans); 

//     sort(ans.begin(), ans.end());

//     // Print all permutations
//     cout << "All permutations:\n";
//     for (const auto perm : ans) {
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     // Find the next permutation
//     vector<int> next_permutation = findNext(ans, next);

//     // Print the next permutation
//     if (!next_permutation.empty()) {
//         cout << "Next permutation after {3, 1, 2} is: ";
//         for (int num : next_permutation) {
//             cout << num << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "{3, 1, 2} not found in permutations." << endl;
//     }

//     return 0;
// }

//better solution
// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main() {
//     int arr[] = {1,2,3};
    
//     next_permutation(arr,arr+3);//using in-built function of C++
    
//     cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
//     return 0;
// }




//optimal solution
// #include<bits/stdc++.h>
// using namespace std;

// vector<int> nextGreatestPermutation(vector<int> arr,int n)

// {
//     int index=-1;
//     //find the break point - the point where a[i]<a[i+1]
//     for(int i=n-2;i>=0;i--)
//     {
//         if (arr[i]<arr[i+1])
//         {
//             index=i;
//             break;
//         }
//     }
    //lets say there is no break point -meaning there is a continuos steep from beginning to end of the array 
    // for example lets say the array is [1,2,3,4,5], here the break point is from 4 so u can do [1,2,3,5,4]
    // but lets say  as we know [5,4,3,2,1] is the last permutation of this family as from 1 there is a sharp increase and no dip ,in that case index=-1 so your next permuation will be [1,2,3,4,5]-the first permuation in this family obtained by reversing
    // if (index ==-1)
    // {
    //     reverse(arr.begin(),arr.end());
    //     return arr;
    // }

    //lets say index!=-1 and a dip is obtained
    //our next step is to find a number closest to the number at the index
    // example {2,1,5,4,3,0,0}-lets say here index is at 1 as 1<5 a[i]<a[i+1] hence now frm 5 to 0,i have to find the no that comes closest to 1
//     for(int i=n-1;i>index;i--)
//     {
//         if (arr[i]>arr[index])
//         {
//             swap(arr[i],arr[index]);//  2,3 | 5,4,1,0,0 and then reverse the right part as i want the smallest in the family where 3 is the second number
//             break;
//         }
//     }
//     reverse(arr.begin()+index+1,arr.end());
//     return arr;

// }

// int main()
// {
//     vector<int> arr={2,1,5,4,3,0,0};
//     int n=arr.size();
//     vector<int> result=nextGreatestPermutation(arr,n);
//     for(auto it:result)
//     {
//         cout<<it<<" ";
//     }
//     return 0;
// }