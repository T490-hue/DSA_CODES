#include<bits/stdc++.h>
using namespace std;


int upperbound(vector<int>& arr,int m,int x)
{
    int low=0;
    int high=m-1;
    int ans=m;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int countsmallerequals(vector<vector<int>>& arr,int n,int m,int x)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=upperbound(arr[i],m,x); //calling the upperbound function for each row to check how many elements are lesser than or equal to mid
    }
    return cnt;
}
int median1(vector<vector<int>>& arr,int n,int m)
{
    int low=INT_MAX;
    int high=INT_MIN;
    int req=(n*m)/2;
    for(int i=0;i<n;i++)
    {
        low=min(low,arr[i][0]);
        high=max(high,arr[i][m-1]);
    }

    while (low<=high)
    {
        int mid=(low+high)/2;
        int smallerEquals=countsmallerequals(arr,n,m,mid);
        if (smallerEquals<=req)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}

int main()
{
        vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int n = matrix.size(), m = matrix[0].size();
    int median=median1(matrix,n,m);
    cout<<median;
    return 0;
}