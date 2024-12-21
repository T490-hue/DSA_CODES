#include<bits/stdc++.h>
#include<climits>
using namespace std;


// vector<int> leaders(vector<int> arr,int n)
// {
//     bool leader;
//     vector<int> leadersarray;
//     for(int i=0;i<n;i++)
//     {
//         leader=true;
//         for(int j=i+1;j<n;j++)
//         {
//             if (arr[i]<arr[j])
//             {
//                 leader=false;
//                 break;
//             }

//         }
//         if(leader==true){
//         leadersarray.push_back(arr[i]);
//         }
//     }
//     return leadersarray;

// }

//optimal solution is when {10,22,12,3,0,6}-here kets take 12 ,what is the max imum in the rhs of 12 -6  and 12 >6 ,hence 12 will be greater than all the elements to its RHS --hence 12 is the leader 


vector<int> leaders(vector<int> arr,int n)
{
int maxi=INT_MIN;
vector<int> leadersarray;
for(int i=n-1;i>=0;i--)
{
    if (arr[i]>maxi)
    {
        maxi=max(maxi,arr[i]);
        leadersarray.push_back(maxi);//or  leadersarray.push_back(arr[i]);
    }
}
return leadersarray;
}

    int main()
{
    vector<int> arr={10,22,12,3,0,6};
    vector<int> result=leaders(arr,arr.size());
    for(auto it:result)
    {
        cout<<it<<" ";
    }
    return 0;
}