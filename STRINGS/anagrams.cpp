#include<bits/stdc++.h>
using namespace std;

// vector<vector<string>> anagramsprinting(vector<string> strs)
// {
//     unordered_map<string,vector<string>> grouped;
//     for(string str:strs)
//     {
//         string sortedstr=str;
//         sort(sortedstr.begin(),sortedstr.end());

//         grouped[sortedstr].push_back(str);
//     }

//     vector<vector<string>> result;
//     //using an iterator to access the elements
//     for(auto it=grouped.begin();it!=grouped.end();it++)
//     {
//         result.push_back(it->second); //If it were a regular object (not an iterator), you'd use the dot (.) operator like this
//     }
//     return result;
// }


string getFrequency(const string &s)
{
    vector<int> freq(26,0); //n is 26 and i want it to be filled by 0
    for(char c:s)
    {
        freq[c-'a']++;
    }
    string freqstring;
    for(int i=0;i<26;i++)
    {
        if (freq[i]>0)
        {
            freqstring+='a'+i;
            freqstring+=to_string(freq[i]);
        }
    }
return freqstring;

}

vector<vector<string>> anagramprinting(vector<string> &strs)
{
unordered_map<string,vector<string>> frequencystringMap;
for(auto str:strs)
{
    string frequency_string=getFrequency(str);
    frequencystringMap[frequency_string].push_back(str);
}
vector<vector<string>> result;
for(auto pair:frequencystringMap)
{
    result.push_back(pair.second);
}
return result;
}

int main()
{
        vector<string> strs = {"listen", "silent", "enlist", "rat", "tar", "art", "god", "dog"};
        vector<vector<string>> result=anagramprinting(strs);

      for (auto it : result) {
    for (auto i : it) {
        cout << i<<",";
    }
    cout<<endl;
}

        return 0;
}