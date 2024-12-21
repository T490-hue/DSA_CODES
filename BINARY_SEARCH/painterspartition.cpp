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

int calstudents(vector<int>& arr,int units)
{
    int cntpainters=1;
    int paint_painter=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if (paint_painter+arr[i]<=units)
            paint_painter+=arr[i];
        else
        {
            cntpainters++;
            paint_painter=arr[i];
        }
    }
    return cntpainters;
}

int mintime(vector<int>& arr,int m)
{
    int maxi=calculatemaximum(arr);
    int summation=maxi*(maxi+1)/2;
    int low=maxi;
    int high=summation;
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