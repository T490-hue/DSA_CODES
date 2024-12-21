#include<bits/stdc++.h>
using namespace std;
int calculatemaximum(vector<int>& arr)
{
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
// low is the maximum element of the array because no subarray can have a sum smaller than the largest element.
// high is the total sum of all elements because one possible solution is to not split the array at all, in which case the largest sum would be the total sum.
int calstudents(vector<int>& arr,int units)
{
    int k=1;
    int sum_elements=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if (sum_elements+arr[i]<=units)
            sum_elements+=arr[i];
        else
        {
            k++;
            sum_elements=arr[i];
        }
    }
    return k; //k gives you the no of parts into which the array has to be split
}

int mintime(vector<int>& arr,int m)
{
    int maxi=calculatemaximum(arr);
    int summation=maxi*(maxi+1)/2;
    int low=maxi;
    // int high=summation;
    int high=accumulate(arr.begin(),arr.end(),0);
    while (low<=high)
    {
        int units_tobepainted=(low+high)/2;
        
        if (calstudents(arr,units_tobepainted)<=m)
       
            high=units_tobepainted-1; //reduce the units to be painted so that i can increase the no of painters to make it closer to m
        else
            low=units_tobepainted+1; // increase the units to be painted so that i can decrease the no of painters and make it closer to m
    }
    return low;
}


int main()
{
    vector<int> arr={10,20,30,40};
    int m=2;
    int maximum=mintime(arr,m);
    cout<<maximum;
    return 0;
}