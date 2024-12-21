#include<bits/stdc++.h>
using namespace std;
//brute approach

// vector<vector<int>> inversionpairs(vector<int>& arr,int n)
// {
//     int cnt=0;
//     vector<vector<int>> pairs;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if (arr[i]>2*arr[j])
//                 pairs.push_back({arr[i],arr[j]});
//         }
//     }
//     return pairs;
// }
// int main()
// {
//     vector<int> arr={4,1,2,3,1};
//     int n=arr.size();
//     vector<vector<int>> pairs=inversionpairs(arr,n);
//     for(int i=0;i<pairs.size();i++)
//     {
//         for(int j=0;j<pairs[i].size();j++)
//         {
//             cout<<pairs[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



void merge(vector<int>& arr,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high)
    {
        if (arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;

        }
    }
    while (left<=mid)
    {
         temp.push_back(arr[left]);
        left++;
    }
    while (right<=high)
    {
            temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

}
int countpairs(vector<int> arr,int low,int mid,int high)
{
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while (right<=high && arr[i]>2*arr[right]) {
            right++;
        }

        cnt+=(right-(mid+1));
    }
    return cnt;
}


int mergesort(vector<int>& arr,int low,int high)
{
    int cnt=0;
    if (low>=high)
    {
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;


}

int noofinversions(vector<int>& arr,int n)
{
    int pairs=mergesort(arr,0,n-1);
    return pairs;
}
int main()
{
    vector<int> arr={4,1,2,3,1};
    int pairs=noofinversions(arr,arr.size());
    cout<<pairs<<" ";
    return 0;
}