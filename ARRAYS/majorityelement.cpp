#include<bits/stdc++.h>
using namespace std;


//brute solution -using 2 for loops

// int majorityelement(vector<int> arr)
// {
//     int count;
//     for(int i=0;i<arr.size();i++)
//     {
//         count=0;
//         for(int j=0;j<arr.size();j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 count++;
//             }
//         }

//         if(count>arr.size()/2)
//         {
//             return arr[i];
//         }
//     }
//     return 0;
// }


//better solution - using unordered map O(N) worst case O(n2)
// int majorityelement(vector<int> arr)
// {
//     unordered_map<int,int> mpp;
//     for(int i=0;i<arr.size();i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp)
//     {
//         if (it.second>arr.size()/2)
//         {
//             return it.first;
//         }
//     }
//     return 0;
// }



//optimal solution - using moore's voting algorithm 
int majorityelement(vector<int> arr){

int count=0;
int ele=0;
for(int i=0;i<arr.size();i++)
{
 if(count==0)
 {
    count=1;
    ele=arr[i];
 }
 else if (ele==arr[i])
 {
    count++;
 }
 else{
    count--;
 }
}
int count1=0;
for(int i=0;i<arr.size();i++)
{
    if (arr[i]==ele)
    {
        count1++;
    }

}
if (count1>arr.size()/2)
{
    return ele;
}
return 0;
}





int main(){

    vector<int> arr={7,7,5,7,1,5,7,5,5,7,7,5,5,5,5};
    int result=majorityelement(arr);
    cout<<result<<endl;
    return 0;
}