#include<bits/stdc++.h>
#include<climits>
using namespace std;

//brute solution
// bool linearsearch(vector<int> arr,int ele)
// {
//     for (int i=0;i<arr.size();i++)
//     {
//         if (arr[i]==ele)
//         {
//             return true;
//         }
       
//     }
//      return false;
// }

// int longestconsecutive(vector<int> arr,int n)
// {
//     int longest=-1;
//     int count;
//     int x=0;
//     for(int i=0;i<n;i++)
//     {
//         x=arr[i];
//         count=1;
//         while(linearsearch(arr,x+1)==true)
//         {
//             x=x+1;
//             count=count+1;
//         }
//         longest=max(longest,count);
//     }
//     return longest;

// }
//------------------------------------------------------------------------------------------------------------------------
//better solution
// int longestconsecutive(vector<int> arr,int n)
// {
// sort(arr.begin(),arr.end());
// int longest=-1;
// int count=0;
// int lastsmaller=INT_MIN;
// for(int i=0;i<n;i++)
// {
//     if (arr[i]-1==lastsmaller)
//     {
//         count+=1;
//         lastsmaller=arr[i];
//     }
//     else if (arr[i]-1!=lastsmaller)
//     {
//         count=1;
//         lastsmaller=arr[i];
//     }
//     longest=max(longest,count);
// }
// return longest;
// }
// -----------------------------------------------------------------------------------------------------------------------------------------------
//optimal solution
pair<int,vector<int>> longestconsecutive(vector<int> arr,int n)
{
    int longest=-1;
    unordered_set<int> st;
    vector<int> temp;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end()){
        int count=1;
        int x=it;
        temp.push_back(x);
        while(st.find(x+1)!=st.end())
        {
            
            count+=1;
            x+=1;

            temp.push_back(x);
        }
        if (count>longest)
        {
            longest=count;
            ans=temp;
        }
        
        
    }
    }
    return {longest,ans};
}

int main()
{
    vector<int> arr={102,4,100,1,101,3,2,1,1};
    int n=arr.size();
   auto result=longestconsecutive(arr,n);
    cout<<result.first<<" "<<endl;
    for(int i:result.second)
    {
        cout<<i<<" ";
    }
    return 0;
}