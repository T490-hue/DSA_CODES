#include<bits/stdc++.h>
#include<vector>
using namespace std;


// vector<int> intersectarray(vector<int> a,vector<int> b ,int n1,int n2)
// {
//     vector<int> ints;
//     vector<int> visited(n2,0);
//     for(int i=0;i<n1;i++)
//     {
//         for(int j=0;j<n2;j++)
//         {
//             if (visited[j]==0 && a[i]==b[j])
//             {
//                 ints.push_back(a[i]);
//                 visited[j]=1;
//                 break;
//             }
//             if (b[j]>a[i])
//             {
//                 break;
//             }

//         }
//     }
//     return ints;

// }

vector<int> intersectarray(vector<int> a,vector<int> b ,int n1,int n2)
{
    vector<int> ints;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if (a[i]<b[j])
        {
            i++;
        }
        if (a[i]>b[j])
        {
            j++;
        }
        if (a[i]==b[j])
        {
            ints.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ints;
}





int main()
{
    // vector<int> a={1,2,2,3,3,5,6};
    vector<int> a={1,2,2,3,3,4,5,6};
    // vector<int> b={2,3,3,5,6,6,7};
    vector<int> b={2,3,3,5,6,6,7};

    int n1=a.size();
    int n2=b.size();
    vector<int> ints=intersectarray(a,b,n1,n2);
    for(int i:ints)
    {
        cout<<i<<endl;
    }
return 0;

}