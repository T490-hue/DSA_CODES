#include<bits/stdc++.h>
#include<vector>
using namespace std;

//brute soltuion -using set O(nlogn) +O(n)
// vector<int>  unionArr(vector<int> a,vector<int> b ,int n1,int n2)
// {
//     set<int> st;
//     for(int i=0;i<n1;i++)
//     {
//         st.insert(a[i]);
//     }
//         for(int i=0;i<n2;i++)
//     {
//         st.insert(b[i]);
//     }
//    vector<int> unionArray(st.size());
//    int index=0;
//    for(auto it:st)
//    {
//     unionArray[index]=it;
//     index++;
//    }
//     return unionArray;
// }

vector<int>  unionArr(vector<int> a,vector<int> b ,int n1,int n2)
{
    int i=0;
    int j=0;
    vector<int> unionarray;
    while (i <n1 && j<n2)
    {
        if (a[i]<=b[j])
        {
            if (unionarray.size()==0 || unionarray.back()!=a[i])
            {
                unionarray.push_back(a[i]);

            }
            i++;
        }
        else{
            if (b[j]<a[i])
            {
                if (unionarray.size()==0 || unionarray.back()!=b[j])
            {
                unionarray.push_back(a[i]);

            }
            j++;
            }
        }
    }
      while (i <n1 )
    {
     
            if (unionarray.size()==0 || unionarray.back()!=a[i])
            {
                unionarray.push_back(a[i]);

            }
            i++;
        }
    
      while (j<n2)
    {
            if (unionarray.size()==0 || unionarray.back()!=b[j])
            {
                unionarray.push_back(b[j]);

            }
            j++;
        }
    
return unionarray;
}


int main()
{
    vector<int> a={1,1,2,3,4,5};
    vector<int> b={2,3,4,4,5,6};
    int n1=a.size();
    int n2=b.size();
    vector<int> uni=unionArr(a,b,n1,n2);
    for(int i:uni)
    {
        cout<<i<<endl;
    }
return 0;
}