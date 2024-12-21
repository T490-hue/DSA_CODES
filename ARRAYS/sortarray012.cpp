#include<bits/stdc++.h>
using namespace std;
//brute-using merge sort technique 



//better solution -to count the no of 0,1,2

// vector<int> sorted(vector<int> arr,int n)
// {
//     int count0=0,count1=0,count2=0;
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]==0)
//         {
//             count0++;
//         }
//         else if (arr[i]==1)
//         {
//             count1++;
//         }
//         else{
//             count2++;
//         }
//     }

//     for(int i=0;i<count0;i++)
//     {
//         arr[i]=0;
//     }
//     for(int i=count0;i<count0+count1;i++)
//     {
//         arr[i]=1;
//     }
//     for(int i=count1+count2;i<n;i++)
//     {
//         arr[i]=2;
//     }
//     return arr;

// }


//optimal solution - DNF algorithm

vector<int> sorted(vector<int> arr,int n){

    int low=0,mid=0,high=n-1;
    while( mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }

    }
    return arr;
}


int main()
{
    vector<int> arr={0,1,2,0,1,2,1,2,0,0,0,1};
    int n=arr.size();
    vector<int> result=sorted(arr,n);
    for(int i:result)
    {
        cout<<i<<" ";
    }
    return 0;
}