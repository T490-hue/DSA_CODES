#include<bits/stdc++.h>
using namespace std;


int timetakentorot(vector<vector<int>>& grid)
{
int n=grid.size();
int m=grid[0].size();
int vis[n][m];
int cntFresh=0;
queue<pair<pair<int,int>,int>> q;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if (grid[i][j]==2)
        {
            q.push({{i,j},0});
            vis[i][j]=2;
        }
        else // if its 0 or 1
        {
            vis[i][j]=0;
        }
        if (grid[i][j]==1)
        cntFresh++;

    }
}

int tm=0;
int cnt=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
while (!q.empty())
{
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
    q.pop();
    tm=max(tm,t);

    for(int i=0;i<4;i++)
    {
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
        {
            q.push({{nrow,ncol},t+1});
            vis[nrow][ncol]=2;
            cnt++;
        }
        
    }
 
}
   if (cnt!=cntFresh)
    {
        return -1;
    }
    return tm;
}

int main()
{
    vector<vector<int>> grid={{0,1,2},{0,1,1},{2,1,1}};
    cout<<timetakentorot(grid)<<"sec";
    return 0;
}