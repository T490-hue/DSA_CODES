#include<bits/stdc++.h>
using namespace std;

//method 1 -swap

// string reversestring(string &s)
// {
//     int n=s.size();
//     int low=0;
//     int high=n-1;
//     while(low<=high)
//     {
//         swap(s[low],s[high]);
//         low++;
//         high--;
//     }
//     return s;
// }

// int main()

// {
//     string s="hello";
//     string reversed=reversestring(s);
//     cout<<reversed;
//     return 0;
// }
//method 2-recursive
string reversestring(string &s,int low,int high)
{
    int n=s.size();
    if (low>high)
    {
        return s;
    }
    swap(s[low],s[high]);
    return reversestring(s,low+1,high-1);
}


int main()

{
    string s="hello  teena";
    int low=0;
    int high=s.size()-1;
    string reversed=reversestring(s,low,high);
    cout<<reversed;
    return 0;
}

//method 3 -stack method
// vector<char> reversestring(string &s)
// {
//     stack<char> s1;
//     for(char ch:s)
//     {
//         s1.push(ch);
//     }
//     vector<char> result;
//     while (!s1.empty())
//     {
//         result.push_back(s1.top());
//         s1.pop();
//     }
//     return result;

// }
// int main()
// {
//     string s="hello buddy";
//     vector<char> reversed=reversestring(s);
//     for (auto it:reversed)
//     {
//         cout<<it<<" ";
//     }
//     return 0;
// }