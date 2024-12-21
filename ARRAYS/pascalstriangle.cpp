#include<bits/stdc++.h>
using namespace std;


int funcNCR(int n,int r)
{
    long long res=1;
    for(int i=0;i<r;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)res;

}
// int pascaltraingle(int R,int C)
// {
//     int value=funcNCR(R-1,C-1);
//     return value;
// }

// void printrow(int n)
// {
//     for(int c=1;c<=n;c++)
//     {
//         cout<<funcNCR(n-1,c-1)<<" ";
//     }
//     cout<<endl;
// }



vector<vector<int>> pascalsprint(int n)
{
vector<vector<int>> ans;
for(int row=1;row<=n;row++)
{
    vector<int> templist;
    for(int col=1;col<=row;col++)
    {
        templist.push_back(funcNCR(row-1,col-1));
    }
    ans.push_back(templist);
}
return ans;
}
int main()

{
    int R=5;//row number
    int C=3;//column number
    int n=6;//row number to print
    // int result=pascaltraingle(R,C);
    // printrow(n);
    // cout<<result;
    vector<vector<int>> ans=pascalsprint(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}