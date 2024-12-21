#include<bits/stdc++.h>
using namespace std;


// int nthroot(int m,int n)
// {
//     int ans=-1;
//     for(int i=1;i<m;i++)
//     {
//         if (pow(i,n)==m)
//             ans=i;        
//     }
//     return ans;
// }



int func(int mid,int n,int m) //m is the number ,n is the power
{
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*mid;
        if (ans>m) //lets say the m is 10^9 and n is 10 so the mid is 10^9/2 now if we multiply 10^9 , 10 times it will become 10^90 so that cant be stored so i will elimate the higher part/right part
        return 2;
    }
    if (ans==m)
    return 1;
    else // if its less than m ,eliminate the left part ,the square root must be in the right part
    return 0;

}


int nthroot(int m,int n)
{
int low=1;
int high=m;
while (low<=high)
{
    int mid=(low+high)/2;

    int midN=func(mid,n,m);
    if (midN==2)
    {
        high=mid-1; // hey bro your power value is increasin the number itself so may be the square root could be on the lower part
    }
    else if (midN==1)
    {
        return mid;
    }
    else //hey the value is less even after multiplying mid n times i am not getting m so may be try increasing yout low
    {
        low=mid+1;
    }
} 
return -1;
}

int main()
{
    int m=216;
    int n=3;
    int value=nthroot(m,n);
    cout<<value<<" ";
    return 0;
}