#include<bits/stdc++.h>
using namespace std;

// bool isValidParenthesis(const string &s)
// {
//     stack<char> st;
//     unordered_map<char,char> mpp={
//         {'}','{'},
//         {')','('},
//         {']','['}
//     };

//     for(int i=0;i<s.size();i++)
//     {
//         char c=s[i];

//         if (mpp.find(c)==mpp.end())
//         {
//             st.push(c);
//         }
//         else //
//         {
//             if (st.empty() || st.top()!=mpp[c])
//             {
//                 return false;
//             }
//             st.pop();
//         }
//     }
//     return st.empty();
// }


// int main()
// {
//         string s = "()[]{}";
//         bool isorno=isValidParenthesis(s);
//         cout<<isorno;
//         return 0;
// }

class Solution {
    unordered_map<char, char> mpp;
public:
    Solution() {
        // Initialize the map with closing brackets and their matching opening brackets
        mpp['}'] = '{';
        mpp[')'] = '(';
        mpp[']'] = '[';
    }

int getTop(const string &s,int index)
{
   int right=0;
   while (index>=0)
   {
    char c=s[index];
    //if top is pointing to a closed bracket increment right
    if (mpp.find(c)!=mpp.end())
    {
        right++;
    }
    else
    {
        right--;
    }
    if (right<0)
    {
        return index;
    }
    index--;
   }
   return -1; 
}
bool isValidParenthesis(const string &s)
{
    int top=-1;

    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        //if its a n open bracket just treat it like the push operation top will always want to carry the opening bracket
        if (mpp.find(c)==mpp.end())
        {
            top=i;
        }
        else //its an closed bracket
        {
            if (top==-1 || mpp[c]!=s[top])
            {
                return false;
            }
            else //if its equal then find the next top
            {
                top=getTop(s,top-1);
            }
        }
    }
    return top==-1;
}
};
int main()
{
    Solution sol;
    string s = "()[]{[()]}";
    if (sol.isValidParenthesis(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}