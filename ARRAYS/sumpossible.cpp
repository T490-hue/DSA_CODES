#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//brute solution -using 2 for loops-O(n2)

// vector<int> findPair(int arr[],int n,int target)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if (arr[i]+arr[j]==target)
//             {
//                 return {i,j};
//             }
//         }
//     }
//     return {};

// }




//using map
// vector<int> findPair(vector<int> book,int n,int target){

// map<int,int> mpp;
// for(int i=0;i<n;i++)
// {
//     int num=book[i];
//     int more=target-num;
//     if (mpp.find(more)!=mpp.end())
//     {
//         return {mpp[more],i};
//     }
//     else
//     {
//         mpp[num]=i;
//     }
// }
// return {};
// }

//optimal solution-using left and right pointer
vector<int> findPair(vector<int> book,int n,int target)
{
    int left=0,right=n-1;
    int s=0;
    for(int i=0;i<n;i++)
    {
        s=book[left]+book[right];
        if (s==target)
        {
            return {left,right};
        }
        else if (s<target)
        {
            left++;
        }
        else{
            right--;
        }
    }
    return {};
}



int main()
{
    vector<int> book={2,6,5,8,11};
    int n=book.size();
    int target=14;
    vector<int> result= findPair(book,n,target);
    for(int i:result){
    cout<<i<<endl;
    }
    return 0;
}