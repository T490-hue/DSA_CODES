#include<bits/stdc++.h>
using namespace std;

//brute method
// string longestcommon(vector<string> s)
// {
//     string prefix="";
//     int index=0;
//     bool ismatch = true;

//     while (index<s[0].size())
//     {
//         char ref=s[0][index];
//         for(int j=1;j<s.size();j++)
//         {
//             if (s[j][index]!=ref || index>=s[j].size())
//             {
//                ismatch=false;
//                break;
//             }
//         }
//         if (!ismatch) {
//             break;  // Stop if a mismatch is found
//         }
  
//         prefix+=ref;
//         index++;
        
//     }
//     return prefix;
// }
//efficient method
string longestcommon(vector<string>& s)
{
    string prefix="";
    sort(s.begin(),s.end());
    string first=s[0];
    string last=s[s.size()-1];
    for(int i=0;i<first.size();i++)
    {
        if (first[i]!=last[i])
        break;
        prefix+=first[i];
    }
    return prefix;
}
int main()
{
    vector<string> s={"flower","floral","flu"};
    cout<<longestcommon(s);
    return 0;
}
