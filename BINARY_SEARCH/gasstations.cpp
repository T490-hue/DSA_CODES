#include<bits/stdc++.h>
using namespace std;

//brute solution
// long double maxdistancebetweengasstations(vector<int>& arr,int k)
// {
//     int n=arr.size();
//     vector<int> howmany(n-1,0);
//     for(int gasStations=1;gasStations<=k;gasStations++)
//     {
//         long double maxSection=-1;
//         int maxInd=-1;
//         for(int i=0;i<n-1;i++)
//         {
//             long double diff=arr[i+1]-arr[i];
//             long double sectionLength=diff/(long double) howmany[i]+1;
//             if (sectionLength>maxSection)
//             {
//                 maxSection=sectionLength;
//                 maxInd=i;
//             }

//         }
//         howmany[maxInd]++;
//     }

//     long double maxAns=-1;
//     for(int i=0;i<n-1;i++)
//     {
//         long double diff=arr[i+1]-arr[i];
//         long double sectionLeng=diff/(long double)(howmany[i]+1);
//         maxAns=max(maxAns,sectionLeng);
//     }
//     return maxAns;

// }



//better solution- using priority queue -insertion of elements into a priotity queue takes log n time
// long double maxdistancebetweengasstations(vector<int>&arr,int k)
// {
//     int n=arr.size();
//     vector<int> howmany(n-1,0);
//     priority_queue<pair<long double,int>> pq;
//     //first push the differences into the queue
//     for(int i=0;i<n-1;i++)
//     {
//         pq.push({arr[i+1]-arr[i],i});
//     }
//     for(int gasStations=1;gasStations<=k;gasStations++)
//     {
//         auto tp=pq.top();
//         pq.pop();
//         int secInd=tp.second;
//         howmany[secInd]++;
//         long double initialdiff= arr[secInd+1]-arr[secInd];
//         long double newdiff= initialdiff/(long double)(howmany[secInd]+1);
//         pq.push({newdiff,secInd});
//     }
//     return pq.top().first;
// }



//optimal solution -using BS

int cntStations(long double dist,vector<int>& arr)
{
    int cnt=0;
    for(int i=1;i<arr.size();i++)
    {
        int numberofstationsinbetween= ((arr[i]-arr[i-1])/dist); // if dist is 0.4 then this value is 2..
        if ((arr[i]-arr[i-1])/dist == numberofstationsinbetween*dist)// 1/0.4 != 2*0.4 
        {
            numberofstationsinbetween--;
        }
        cnt+=numberofstationsinbetween;
    }
    return cnt;
}
long double maxdistancebetweengasstations(vector<int>& arr,int k)
{

    int n=arr.size();
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++)
    {
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff=1e-6;
    while (high-low>diff)
    {
        long double mid=(low+high)/(2.0);
        int cntgasStations=cntStations(mid,arr);
        if ( cntgasStations>k)
        {
            low=mid;
        }
        else //f its less than then , i need to decrese the distance so that i can make it closer to k and if its equal i need to find the min distance so i need to eliminate right
        {
            high=mid;
        }
       //because the right answer will be at high 
    }
     return high; 
}
int main()
{
    vector<int> arr={1,13,17,23};
    int k=5;
    long double maxdistance=maxdistancebetweengasstations(arr,k);
    cout<<maxdistance;
    return 0;
}