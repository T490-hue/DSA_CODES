#include<iostream>
#include<climits>
using namespace std;

// Brute solution-sort the elements and the element a[n-2] is the second largest -o(n log n)+o(n)
// void sort(int arr[],int n)
// {
//     int min;
//     int temp;
//     for(int i=0;i<n-1;i++)
//     {
//         min=i;
//         for(int j=i+1;j<n;j++)
//     {
//         if(arr[min]>arr[j])
//         {
//             min=j;
//         }
//     }

//     temp=arr[i];
//     arr[i]=arr[min];
//     arr[min]=temp;
    
//     }
    
// }


//better solution-O(2n)

// int secondlargest(int arr[],int n)
// {
// int largest=arr[0];
// for(int i=1;i<n;i++)
// {
//     if (arr[i]>largest){
//         largest=arr[i];
//     }

// }
// int slargest=-1;
// for(int i=0;i<n;i++)
// {
//     if(arr[i]!=largest && arr[i]>slargest)
//     {
//         slargest=arr[i];
//     }
// }
// return slargest;
// }



//optimal solution -o(n)

int secondlargest(int arr[],int n)
{
    int largest=INT_MIN;
    int slargest=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            slargest=largest;
            largest=arr[i];
        }
        if (arr[i]!=largest && arr[i]>slargest)
        {
            slargest=arr[i];
        }
    }
    return slargest;

}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result=secondlargest(arr, n);  // Call the sort function

    cout << "Second largest element: ";
    
    cout <<result<< " ";
    
    cout << endl;

    return 0;
}