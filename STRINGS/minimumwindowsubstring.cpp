#include<bits/stdc++.h>
using namespace std;

// string minimumwindow(const string &s,const string &t)
// {
//     int min_length=INT_MAX;
//     int sIndex=-1;
//     int cnt;
//     for(int i=0;i<s.size();i++)
//     {       
//         cnt=0;
//         unordered_map<char,int> map;
//         for(char c:t)
//         {
//             map[c]++;
//         }
//         for(int j=i;j<s.size();j++)
//         {
//             if (map.find(s[j])!=map.end())
//             {
//             int freq=s[j];
            
//             if (freq>0)
//             {
//                 cnt+=1;
//             }
//             map[s[j]]--;
          

//             if (cnt==t.size())
//             {
//                 if (j-i+1<min_length)
//                 {
//                     min_length=j-i+1;
//                     sIndex=i;
//                     break;
//                 }
//             }
//         }
//     }
//     }
//     return s.substr(sIndex,min_length);
// }


string minimumwindow(const string &s,const string &t)
{
    int sIndex=-1;
    int min_length=INT_MAX;
    int cnt;
    for(int i=0;i<s.size();i++)
    {
        int hash[256]={0};
        cnt=0;
        for(int j=0;j<t.size();j++)
        {
            hash[t[j]]++;
        }
        for(int j=i;j<s.size();j++)
        {
            if (hash[s[j]]>0)
            {
                cnt++;
            }
            hash[s[j]]--;

            if (cnt==t.size())
            {
                if (j-i+1<min_length)
                {
                    min_length=j-i+1;
                    sIndex=i;
                    break;
                }
            }
        }
    }
    return s.substr(sIndex,min_length);   
}



// string minimumwindow(const string &s,const string &t)
// {
//   int sIndex=-1;
//   int min_length=INT_MAX;
//   unordered_map<char,int> map;
//   for(char c:t)
//   {
//     map[c]++;
//   }  
//   int i=0,j=0,cnt=t.size();
//   while(j<s.size())
//   {
//     char ch=s[j];
//     if (map[ch]>0)
//     {
//         cnt--;
//     }
//     map[ch]--;
//     while (cnt==0)
//     {
//         int curr_windowsize=j-i+1;
//         if (curr_windowsize<min_length)
//         {
//             min_length=curr_windowsize;
//             sIndex=i;
//         }
//         map[s[i]]++;
//         if (map[s[i]]>0)
//         {
//             cnt++;
//         }
//         i++;
//     }
//     j++;
//   }
//   return s.substr(sIndex,min_length);
// }
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string out=minimumwindow(s,t);
    cout<<out;
    return 0; 
}