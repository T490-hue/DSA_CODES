#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> inversionpairs(vector<int> arr,int n)
// {
//     int cnt=0;
//     vector<vector<int>> pairs;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if (arr[i]>arr[j])
//                 pairs.push_back({arr[i],arr[j]});
//         }
//     }
//     return pairs;
// }
// int main()
// {
//     vector<int> arr={5,3,2,4,1};
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




//merge sort with counting inversions

int merge(vector<int>& arr,int low,int mid,int high)
{
    int cnt=0;
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
            cnt+=(mid-left+1);
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
    cnt+=merge(arr,low,mid,high);
    return cnt;


}

int noofinversions(vector<int>& arr,int n)
{
    int pairs=mergesort(arr,0,n-1);
    return pairs;
}
int main()
{
    vector<int> arr={5, 4, 3, 2, 1};;
    int pairs=noofinversions(arr,arr.size());
    cout<<pairs<<" ";
    return 0;
}