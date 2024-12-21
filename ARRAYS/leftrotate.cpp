#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//brute solution -to create another array

//better solution

// void leftRotate(int arr[],int n)
// {
//     int temp=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         arr[i-1]=arr[i];
//     }
//     arr[n-1]=temp;

//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }




//to rotate by d places
// void leftRotate(int arr[],int n,int d)
// {
//     d=d%n;
//     int temp[d];
//     for(int i=0;i<d;i++)
//     {
//         temp[i]=arr[i];
//     }
//     for(int i=d;i<n;i++)
//     {
//         arr[i-d]=arr[i];
//     }
//     for(int i=n-d;i<n;i++)
//     {
//         arr[i]=temp[i-(n-d)];
//     }
//         for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// }

void leftRotate(int arr[],int n,int d)
{

reverse(arr,arr+d);
reverse(arr+d,arr+n);
reverse(arr,arr+n);

        for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}


int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d;
    cin>>d;
    leftRotate(arr,n,d);
    return 0;
}

// int main()
// {
//     int arr[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(arr[0]);

//     leftRotate(arr,n);
//     return 0;
// }