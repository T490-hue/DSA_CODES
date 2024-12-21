#include<bits/stdc++.h>
using namespace std;

void mergesorted(vector<int>& arr1,vector<int>& arr2,int n,int m)
{
    int left=0;
    int right=0;
    int index=0;
    vector<int> arr3(n+m);
    while(left<n && right<m)
    {
        if (arr1[left]<=arr2[right])
        {
            arr3[index]=arr1[left];
            left++;
            index++;
        }
        else{
            arr3[index]=arr2[right];
            right++;
            index++;

        }
    }
    while (left<n)
    {
        arr3[index]=arr1[left];
        left++;
        index++;
    }
    while (right<m)
    {
        arr3[index]=arr2[right];
        right++;
        index++; 
    }

    for(int i=0;i<n+m;i++)
    {
        if (i<n)
        {
            arr1[i]=arr3[i];
        }
        else{
            arr2[i-n]=arr3[i];
        }


    }
}

//optimal approach 1

// void mergesorted(vector<int>& arr1,vector<int>& arr2,int n,int m)
// {
//     int left=n-1;
//     int right=0;
//     while( left>=0 && right<m)
//     {
//         if (arr1[left]>arr2[right])
//         {
//             swap(arr1[left],arr2[right]);
//             left--;
//             right++;
//         }
//         else //i know it will be sorted
//         {
//             break;
//         }
//     }
//     sort(arr1.begin(),arr1.end());
//     sort(arr2.begin(),arr2.end());
// }



//optimal approach2
// void swapifgreater(vector<int>& arr1,vector<int>& arr2,int ind1,int ind2)
// {
//     if (arr1[ind1]>arr2[ind2])
//     {
//         swap(arr1[ind1],arr2[ind2]);
//     }
// }

// void mergesorted(vector<int>& arr1,vector<int>& arr2,int n,int m)
// {
//     int len=n+m;
//     int gap=(len/2)+(len%2);
//     while(gap>0)
//     {
//         int left=0;
//         int right=left+gap;
//         while (right<len)
//         {
//             if(left<n && right>=n)  //left is in arr1 and right is in arr2
//             {
//                 swapifgreater(arr1,arr2,left,right-n);
//             }
//             else if (left>=n) //both left and right are in arr2
//             {
//                 swapifgreater(arr2,arr2,left-n,right-n);
//             }
//             else{
//                 swapifgreater(arr1,arr1,left,right);
//             }
//             left++;
//             right++;
//         }
//         if (gap==1)
//         break;
//         gap=(gap/2)+(gap%2);
//     }
// }

int main()
{
    vector<int> arr1={1, 4, 8, 10};
    vector<int> arr2={2, 3, 9};
    int n=4;
    int m=3;
    mergesorted(arr1,arr2,n,m);
    for(auto it:arr1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:arr2)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}