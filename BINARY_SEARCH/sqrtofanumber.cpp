#include<bits/stdc++.h>
using namespace std;

//brute approach

// int sqrt_number(int n)
// {
//     int ans=1;
//     for(int i=1;i<=n;i++){
//         if (i*i <=n)
//             ans=i;
//         else
//             break;
//     }
//     return ans;
// }


//optimal approach -using binary search

    int sqrt_number(int x) {

        int low=1;
        int high=x;
        int ans=-1;
        if (x==0) return 0;
        while (low<=high)
        {
            int mid = low + (high - low) / 2;
            if (mid <= x / mid) {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
int main()

{
    int n=28;
    int sqrt=sqrt_number(n);
    cout<<sqrt;
    return 0;
}