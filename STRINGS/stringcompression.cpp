#include<bits/stdc++.h>
using namespace std;

// string compressstring(string &s)
// {
// int cnt;
// string new_compressed=" ";
// unordered_set<char> processed;
// for(int i=0;i<s.size();i++){
// if (processed.find(s[i])==processed.end()){
// cnt=0;

// for(int j=0;j<s.size();j++)
// {
//     if (s[i]==s[j])
//     {
//         cnt++;
//     }
// }

// if (cnt>0 && s[i])
// {
// new_compressed+=s[i]+to_string(cnt);
// processed.insert(s[i]);
// }
// }
// }
// return new_compressed;
// }

//hash table method
// string compressstring(string &s)
// {
//     unordered_map<char,int> mpp;
//     string new_compressed=" ";
//     for(char c:s)
//     {
//         mpp[c]++;
//     }
//     for(auto it:mpp)
//     {
//         if (it.second>0)
//         {
//         new_compressed+=it.first;
//         new_compressed+=to_string(it.second);
//         }
//     }
//     return new_compressed;
// }

//method 3 -O(N) space and time complexity
vector<char> compressstring(vector<char> &s)
{
    int n=s.size();
    int cnt;
    int i=0;
    int index=0;
    while (i<n)
    {
        char ch=s[i];
        cnt=0;
        while(i<n && ch==s[i])
        {
            cnt++;
            i++;
        }
        s[index]=ch;
        index++;
        if (cnt>1)
        {
            string count=to_string(cnt);
            for(char &c:count)
            {
                s[index]=c;
                index++;
            }

        }
    }
    s.resize(index);
    return s;
}
int main()
{
    vector<char> s={'a','a','a','a','a','a','a','a','a','a','b','b','c'};
    vector<char>  s1=compressstring(s);
    for (auto it:s1)
    {
        cout<<it;

    }
    return 0;
}
