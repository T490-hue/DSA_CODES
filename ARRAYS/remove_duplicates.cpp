#include<bits/stdc++.h>
using namespace std;


// brute solution is using a set - O(n log n)+O(n)

// int rem_duplicates(int arr[],int n)
// {
// set<int> st;
// for(int i=0;i<n;i++)
// {
//     st.insert(arr[i]);
// }
// int index=0;
// for(auto it:st)
// {
//     arr[index]=it;
//     index++;
// }
// return index;
// }


//better solution

int rem_duplicates(int arr[], int n) {
    int hash[1001] = {0}; // 
    int i;
    int j = 0;

    // Count occurrences of each element
    for (i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for (i = 0; i < n; i++) {
        if (hash[arr[i]] > 1) {
            arr[j++] = arr[i]; // Add unique element
            hash[arr[i]] = 0;  
        }
    }

    return j; 
}

//optimal solution 
// int rem_duplicates(int arr[],int n)
// {
//     int i=0;
//     for(int j=1;j<n;j++)//we are not considering the first element becuase the first element will always be
//     {
//         if (arr[i]!=arr[j])
//         {
//             arr[i+1]=arr[j];
//             i++;
//         }
//     }
//     return i+1;
// }



int main()
{
    int arr[]={1,1,2,2,2,3,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=rem_duplicates(arr,n);
    cout<<"no of elements : "<<" "<<result<<endl;
    return 0;
}