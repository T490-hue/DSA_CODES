#include<bits/stdc++.h>
using namespace std;


void computelps(string& pat,vector<int>& lps,int M)
{
    int len=0;
    lps[0]=0;

    int i=1;
    while (i<M)
    {
        if (pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else 
        {
            if (len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i=i+1;
            }
        }
    }

}
vector<int> KMP(string& pat,string& txt)
{
    int M=pat.length();
    int N=txt.length();
    int i=0;
    int j=0;
    vector<int> lps(M);
    computelps(pat,lps,M);
    vector<int> result;
    while (N-i>=M-j)
    {
        if (pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if (j==M)
        {
            result.push_back(i-j+1);
            j=lps[j-1];
        }
        else if (i<N && pat[j]!=txt[i])
        {
            if (j!=0)
            {
                j=lps[j-1];
            }
            else //if j=0
            {
                i=i+1;
            }
        }

    }
    return result;

}

int main()
{
    string pat="AABA";
    string txt="AABAACAABAA";
    vector<int> result=KMP(pat,txt);
    for (auto it:result)
    {
        cout<<it<<" ";
    }
    return 0;

}