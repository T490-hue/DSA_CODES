#include<bits/stdc++.h>
using namespace std;


// int numberofsubarraywithsumk(vector<int> arr,int k)
// {
// int count=0;
// int sum;
// for(int i=0;i<arr.size();i++)
// {
//     for(int j=i;j<arr.size();j++)
//     {
//         sum=0;
//         for(int k=i;k<=j;k++)
//         {
//             sum+=arr[k];
//         }
//         if(sum==k)
//         {
//             count++;
//         }
//     }
// }
// return count;
// }


// int numberofsubarraywithsumk(vector<int> arr,int k)
// {
// int count=0;
// int sum;
// for(int i=0;i<arr.size();i++)
// {
//     sum = 0;
//     for(int j=i;j<arr.size();j++)
//     {
        
//         sum+=arr[j];
        
//         if(sum==k)
//         {
//             count++;
//         }
//     }
// }
// return count;
// }


int numberofsubarraywithsumk(vector<int> arr,int k)
{
int prefixsum=0,count=0;
map<int,int> mpp;
 mpp[0] = 1;
 
for(int i=0;i<arr.size();i++)
{
prefixsum+=arr[i];
int remove=prefixsum-k;
count+=mpp[remove];
mpp[prefixsum]+=1;
}

return count;
}
int main()
{
    vector<int> arr={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    int result=numberofsubarraywithsumk(arr,k);
    cout<<result<<endl;
    return 0;
}