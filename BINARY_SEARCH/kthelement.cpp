#include<bits/stdc++.h>
using namespace std;
int kthelement(vector<int>& arr1,vector<int>& arr2,int k)
{
    int n1=arr1.size();
    int n2=arr2.size();
    int n=n1+n2;
    if (n1>n2) return kthelement(arr2,arr1,k);
    int low=max(0,k-n2);
    int high=min(k,n1);
    int left=k;
    
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
             return max(l1,l2);  
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
    int k=6;
    double kth=kthelement(arr1,arr2,k);
    cout<<kth;
    return 0;
}