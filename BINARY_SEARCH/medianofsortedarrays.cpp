#include<bits/stdc++.h>
using namespace std;
// ----------------------------------------------------------------------------------------------------------------------------------------------------
//brute solution
// int medianofsortedarrays(vector<int>& arr3,int n1,int n2)
// {
// int n=n1+n2;
// if (n%2==1){
//     return arr3[n/2];
// }
// else{
//     return (arr3[n/2]+arr3[n/2 -1])/2;
// }
// }

// vector<int> merged(vector<int>& arr1,vector<int>& arr2,int n1,int n2)
// {
//     int i=0;
//     int j=0;
//     vector<int> arr3;
//     while(i<n1 && j<n2)
//     {
//        if (arr1[i]<=arr2[j])
//        {
//             arr3.push_back(arr1[i]);
//             i++;
//        }
//         else {
//             arr3.push_back(arr2[j]);
//             j++;
//         }
//     } 
//     while (i<n1){
//         arr3.push_back(arr1[i]);
//         i++;
//     }
//     while (j<n2){
//         arr3.push_back(arr2[j]);
//         j++;
//     }
//     return arr3;
// }

// int main()
// {
// vector<int> arr1={1,3,4,7,10,12};
// vector<int> arr2={2,3,6,15};
// vector<int> merged_array=merged(arr1,arr2,arr1.size(),arr2.size());
// int median=medianofsortedarrays(merged_array,arr1.size(),arr2.size());
// cout<<median;
// return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------------


// double median (vector<int>& arr1,vector<int>& arr2)
// {
//     int n1=arr1.size();
//     int n2=arr2.size();
//     int n=n1+n2;
//     int ind1=n/2;
//     int ind2=n/2 - 1;
//     int i=0;
//     int j=0;
//     int cnt=0;
//     int ind1ele=-1;
//     int ind2ele=-1;
//     while (i<n1 && j<n2)
//     {
//         if (arr1[i]<arr2[j]){
//             if (cnt==ind1) ind1ele=arr1[i];
//             if (cnt==ind2)  ind2ele=arr1[i];
//             cnt++;
//             i++;
//         }
//         else
//         {
//             if (cnt==ind1) ind1ele=arr2[j];
//             if (cnt==ind2) ind2ele=arr2[j];
//             cnt++;
//             j++;
//         }
//     }
//     while (i<n1)
//     {
//         if (cnt==ind1) ind1ele=arr1[i];
//         if (cnt==ind2) ind2ele=arr1[i];
//         cnt++;
//         i++;
//     }
//      while (j<n2)
//     {
//         if (cnt==ind1) ind1ele=arr2[j];
//         if (cnt==ind2) ind2ele=arr2[j];
//         cnt++;
//         j++;
//     }

//     if (n%2==1)
//         return ind2ele;
//     else
//         return (double)(ind1ele+ind2ele)/2.0;
// }


// -----------------------------------------------------------------------------------------------------------------------------------------------------------
double median(vector<int>& arr1,vector<int>& arr2)
{
    int n1=arr1.size();
    int n2=arr2.size();
    int n=n1+n2;
    if (n1>n2) return median(arr2,arr1);
    int low=0;
    int high=n1;
    int left=(n1+n2+1)/2;
    
    while(low<=high)
    {
        int mid1=(low+high)/2;//no of elements to be picked from the arr1 in the left half
        int mid2=left-mid1;//no of elements to be picked from the arr2 in the left part
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if (mid1<n1) r1=arr1[mid1];
        if (mid2<n2) r2=arr2[mid2];
        if (mid1-1>=0)  l1=arr1[mid1-1];
        if (mid2-1>=0)  l2=arr2[mid2-1];
        if (l1 <=r2 && l2<=r1)
        {
            if (n%2==1)
            {
                return max(l1,l2);
            }
          
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            
        }
        else if (l1>r2)
            high=mid1-1;
        else
            low=mid1+1;
    }
    return 0;
}
int main()
{
    vector<int> arr1={1,3,4,7,10,12};
    vector<int> arr2={2,3,6,15};

    double median_value=median(arr1,arr2);
    cout<<median_value;
    return 0;
}