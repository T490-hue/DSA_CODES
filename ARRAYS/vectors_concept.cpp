#include<vector>
#include<iostream>
using namespace std;
// int main()
// {
//     vector<int> myVec={1,2,3,4,5};
//     cout<<myVec.size()<<endl;
//     myVec.push_back(7);
//     for(int i:myVec)
//     {
//         cout<<i<<endl;
//     }
// }



// int main()
// {
//     int n;
//     cin>>n;

//     vector<int> numbers(n);
//    cout<<"Type the numbers"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cin>>numbers[i];
//     }
//     for(int i:numbers)
//     {
//         cout<<i<<" ";
//     } 
//     return 0;
// }

int main()
{
    int n;
    cin>>n;
    int numbers[n];
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }
    for(int i=0;i<n;i++)
{
    cout<<numbers[i];
}
cout<<"size is"<<sizeof(numbers)/sizeof(numbers[0]);

int n1;
cin>>n1;
int numbers_new[n1];
for(int i=0;i<n1;i++)
{
    numbers_new[i]=numbers[i];
}
cout<<"size is"<<sizeof(numbers_new)/sizeof(numbers_new[0]);


}