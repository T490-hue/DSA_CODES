#include<bits/stdc++.h>
using namespace std;


// bool checkPal(const string &s,int low,int high)
// {
//     while (low<high)
//     {
//         if (s[low]!=s[high])
//             return false;
//         low=low+1;
//         high=high-1;
//     }
//     return true;
// }

// string longestPalindrome(const string &s)
// {
//     int maxlen=-1;
//     int start=0;
//     for(int i=0;i<s.length();i++)
//     {
//         for(int j=i;j<s.length();j++)
//         {
//             if (checkPal(s,i,j) && (j-i+1)>maxlen)
//             {
//                 start=i;
//                 maxlen=j-i+1;
//             }
//         }
//     }
//     return s.substr(start,maxlen);
// }
// -------------------------------------------------------------------------------------------------------------------------------------------------------

//dynamic programming
// string longestPalindrome(string &s)
// {
//     int maxlen=1;
//     int start=0;
//     int n=s.size();
//     vector<vector<bool>> dp(n,vector<bool>(n,false));
//     //for 1 element
//     for(int i=0;i<n;i++)
//     {
//         dp[i][i]=true;
//     }
//     //for two elements
//     for(int i=0;i<n-1;i++)
//     {
//         if (s[i]==s[i+1])
//         {
//             dp[i][i+1]=true;
//             start=i;
//             maxlen=2;
//         }
//     }
//     //for length greater than 3 
//     for(int k=3;k<=n;k++)
//     {
//         for(int i=0;i<n-k+1;i++)
//         {
//             int j=i+k-1;

//             if (dp[i+1][j-1]==true && s[i]==s[j]){
//                 dp[i][j]=true;

//                 if (k>maxlen)
//                 {
//                     start=i;
//                     maxlen=k;
//                 }

//             }
//         }
//     }

// return s.substr(start,maxlen);
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------------
// using expansion method

string longestPalindrome(string &s)
{
    int n=s.length();
    if (n==0) return "";

    int start=0;
    int maxlen=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            int low=i;
            int high=i+j;

            while(low>=0 && high<n && s[low]==s[high])
            {
                int currlen=high-low+1;
                if (currlen>maxlen)
                {
                    start=low;
                    maxlen=currlen;
                }
                low--;
                high++;
            }
        }
    }
    return s.substr(start,maxlen);
}

int main(){
    string s = "ABRBADAADAB";
    cout << longestPalindrome(s) << endl;
    return 0;
}