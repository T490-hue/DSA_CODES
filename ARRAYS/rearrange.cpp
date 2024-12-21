#include<bits/stdc++.h>
using namespace std;

//brute solution
// vector<int> rearranged(vector<int> arr,int n)

// {
// vector<int> pos;
// vector<int> neg;
// for(int i=0;i<n;i++)
// {
//     if (arr[i]<0)
//         neg.push_back(arr[i]);
//     else
//         pos.push_back(arr[i]);
// }
// for(int i=0;i<n/2;i++)
// {
//     arr[2*i]=pos[i];
//     arr[2*i+1]=neg[i];
// }
// return arr;
// }


//optimal solution
// vector<int> rearranged(vector<int> arr,int n)
// {

//     int posindex=0,negindex=1;
//     vector<int> ans(n,0);
//     for(int i=0;i<n;i++)
//     {
//         if (arr[i]<0)
//         {
//             ans[negindex]=arr[i];
//             negindex+=2;
//         }
//         else
//         {
//             ans[posindex]=arr[i];
//             posindex+=2;
//         }
//     }
//     return ans;
// }

//variety 2- if no of positives != no of negatives
vector<int> rearranged(vector<int> arr,int n)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++)
    {
        if (arr[i]>0)
        {
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }


    if (pos.size()>neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }

        int index= neg.size()*2;
        for (int i=index;i<pos.size();i++)
        {
            arr[index]=pos[i];
            index++;
        }

     }
         if (pos.size()<neg.size())
    {
        for(int i=0;i<pos.size();i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }

        int index= pos.size()*2;
        for (int i=index;i<neg.size();i++)
        {
            arr[index]=neg[i];
            index++;
        }

     }
     return arr;
}


int main()
{
    vector<int> arr={3,1,-2,-5,2,-4,7,9};
    vector<int> result=rearranged(arr,arr.size());
    for (int i:result)
    {
        cout<<i<<" ";
    }
    return 0;
}