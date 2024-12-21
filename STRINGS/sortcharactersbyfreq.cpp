#include<bits/stdc++.h>
using namespace std;

// string sortedcharacters(string &s)
// {
//     int freq[128]={0};
//     for(char c:s)
//     {
//         freq[(int)c]++;
//     }
//     vector<pair<char,int>> freqVec;
//     for(int i=0;i<128;i++)
//     {
//         if (freq[i]>0)
//         {
//             freqVec.push_back({(char)i,freq[i]});
//         }
//     }
//     sort(freqVec.begin(),freqVec.end(),[](pair<char,int> &a,pair<char,int> &b){
//         return a.second>b.second;
//     });

//     string result;
//     for(auto &p:freqVec)
//     {
//         result+=string(p.second,p.first);
//     }
//     return result;
// }
// ----------------------------------------------------------------------------------------------------------------------------------------------------
// string sortedcharacters(string &s)
// {
//     string result;

//     vector<int> freq(128,0);

//     for(char c:s)
//     {
//         freq[c]++;
//     }
//     auto cmp=[&](char a,char b){
//         if (freq[a]==freq[b]) return a<b;
//         return freq[a]>freq[b];
//     };
//     sort(s.begin(),s.end(),cmp);
//     return s;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------

// string sortedcharacters(string &s)
// {
//     unordered_map<char,int> freq;
//     for(char c:s)
//     {
//         freq[c]++;
//     }
//     vector<pair<char,int>> freqVec;
//     for (auto [ch,fq] :freq)
//     {
//         freqVec.push_back({ch,fq});
//     }
//     auto cmp=[&](pair<char,int> &a,pair<char,int> &b)
//     {
//         return a.second>b.second;
//     };
//     sort(freqVec.begin(),freqVec.end(),cmp);
//     string result;
//     for (auto [ch,fq] :freqVec)
//     {
//         result+=string(fq,ch);
//     }
//     return result;
// }
// ---------------------------------------------------------------------------------------------------------------------------------------------
string sortedcharacters(string &s)
{
unordered_map<char,int> freq;
for(char c:s)
{
    freq[c]++;
}
vector<vector<char>> bucketarray(s.length()+1);
for(auto [ch,fq]:freq)
{
    bucketarray[fq].push_back(ch);
}
string result;
for(int fp=s.length();fp>=1;fp--)
{
    for (auto ch:bucketarray[fp])
    {
        result.append(fp,ch);
    }
}
return result;
}
//method 4
int main()
{
    string s="tree";
    string sortedchars=sortedcharacters(s);
    cout<<sortedchars;
    return 0;
}