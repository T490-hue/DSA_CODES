#include<bits/stdc++.h>
using namespace std;


// vector<vector<int>> quads(vector<int> arr,int n)
// {
//     set<vector<int>> st;
//     int target=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             for(int k=j+1;j<n;j++)
//             {

//                 for(int l=k+1;l<n;l++)
//                 {
//                     long sum=arr[i]+arr[j];
//                     sum+=arr[k];
//                     sum+=arr[l];
//                     if (sum==target)
//                     {
//                         vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }

//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// vector<vector<int>> quads(vector<int> arr,int n)
// {
// set<vector<int>> st;
// int target=0;
// for(int i=0;i<n;i++)
// {
//     for(int j=i+1;j<n;j++)
//     {
//         set<long long> hashset;
//         for(int k=j+1;k<n;k++)
//         {
//             long long sum=arr[i]+arr[j];
//             sum+=arr[k];
//             long long fourth=target-(sum);
//             if (hashset.find(fourth)!=hashset.end())
//             {
//                 vector<int> temp={arr[i],arr[j],arr[k],(int)fourth};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);

//             }
//             hashset.insert(arr[k]);
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// return ans;
// }


vector<vector<int>> quads(vector<int> arr,int n,int target)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if (j!=i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while (k<l)
            {
                long long sum=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if (sum>target)
                {
                    l--;
                }
                else if (sum<target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])
                    k++;
                    while(k<l && arr[l]==arr[l+1])
                    l--;
                }
            }
        }
    }
    return ans;
}



int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5};
    int n = arr.size();
    int target=8;
    vector<vector<int>> result = quads(arr, n,target);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

