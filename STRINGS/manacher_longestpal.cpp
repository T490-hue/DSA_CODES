#include<bits/stdc++.h>
using namespace std;

#define SIZE 10000+1

int P[SIZE*2];

string convertToNewString(const string &s)
{
    string newstring="@";
    for(int i=0;i<s.size();i++)
    {
        newstring+="#"+s.substr(i,1); //extracts 1 character from index i
    }
    newstring+="$";
    return newstring;
}
string longestpal(const string &s)
{
    string q=convertToNewString(s);
    int c=0;
    int r=0;

    for(int i=1;i<q.size()-1;i++) // you dont include the @ and $
    {
        int mirror=2*c-i;

        if (i<r) // if the palindrome centered at i is within the current palindrome ka boundary
        {
            P[i]=min(P[mirror],r-i);
        }

        //expand the characters around the centre i 
        while (q[i+(1+P[i])]==q[i-(1+P[i])])
        {
            P[i]++;
        }
        
        if (i+P[i]>r)
        {
            c=i;
            r=i+P[i];
        }
    }
    int maxPalindrome=0;
    int centreindex=0;
    for(int i=1;i<q.size()-1;i++)
    {
        if (P[i]>maxPalindrome)
        {
            maxPalindrome=P[i];
            centreindex=i;
        }
    }
    return s.substr((centreindex-1-maxPalindrome)/2,maxPalindrome);
}

int main()
{
    string s="ABRBADAADAB";
    string pal=longestpal(s);
    cout<<pal;
    return 0;

}

