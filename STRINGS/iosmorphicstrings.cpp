#include<bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// bool areIsomorphic(string str1,string str2)
// {
//     bool marked[MAX_CHARS]={false};
//     int m=str1.length();
//     int n=str2.length();
//     if (m!=n)
//         return false;
    
//     int map[MAX_CHARS];
//     memset(map,-1,sizeof(map));
//     for(int i=0;i<m;i++)
//     {
//         if (map[str1[i]]==-1) 
//         {
//             //hey i am seeing str1[i] for  the first time
//             if (marked[str2[i]]==true)
//             {
//                 //hey i already am mapped to someone
//                 return false;
//             }
//             marked[str2[i]]=true;
//             map[str1[i]]=str2[i];

//         }
    
//     else if (map[str1[i]]!=str2[i])
//     {
//         return false;
//     }
//     }
//     return true;
// }


bool areIsomorphic(string str1,string str2){
    int m=str1.length();
    int n=str2.length();
    unordered_map<char,char> characterMappings;
    if (m!=n)
        return false;
    for(int i=0;i<m;i++)
    {
        if (characterMappings.count(str1[i]))
        {
            if (characterMappings[str1[i]]!=str2[i])
                    return false;                
        }
        else {
            vector<char> mappedCharacters;
            for(const auto& pair:characterMappings)
            {
                mappedCharacters.push_back(pair.second);
            }
            if (find(mappedCharacters.begin(),mappedCharacters.end(),str2[i])!=mappedCharacters.end()) return false;
            else
            characterMappings[str1[i]]=str2[i];
         }
    }
    return true;
}
int main()
{
    cout << (areIsomorphic("bad", "kfk") ? "True" : "False")
         << endl;
    return 0;
}
