#include<bits/stdc++.h>
using namespace std;


// vector<vector<int>> triplets(vector<int> arr,int n)
// {
   
//     set<vector<int>> st;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             for(int k=j+1;j<n;j++)
//             {
//                 if (arr[i]+arr[j]+arr[k]==0)
//                 {
//                     vector<int> temp={arr[i],arr[j],arr[k]};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//      vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// vector<vector<int>> triplets(vector<int> arr,int n)
// {
//     set<vector<int>> st;
//     for(int i=0;i<n;i++)
//     {
//         set<int> hashset;
//         for(int j=i+1;j<n;j++)
//         {
//             int third=-(arr[i]+arr[j]);
//             if (hashset.find(third)!=hashset.end())
//             {
//                 vector<int> temp={arr[i],arr[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }



vector<vector<int>> triplets(vector<int> arr,int n)
{
    vector<vector<int>> ans;

for(int i=0;i<n;i++)
{
    if (i>0 && arr[i]==arr[i-1])
    continue;
    int j=i+1;
    int k=n-1;
    while (j<k)
    {
        int sum=arr[i]+arr[j]+arr[k];
        if (sum>0)
        {
            k--;
        }
        else if (sum<0)
        {
            j++;
        }
        else{
            vector<int> temp={arr[i],arr[j],arr[k]};
            ans.push_back(temp);
            j++;
            k--;
            while( j<k && arr[j]==arr[j-1])
            j++;
            while(j<k && arr[k]==arr[k+1])
            k--;
        }
    }
}
return ans;
}
int main()
{
    vector<int> arr={-1,0,1,2,-1,4};
    int n=arr.size();
    vector<vector<int>> result=triplets(arr,n);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}