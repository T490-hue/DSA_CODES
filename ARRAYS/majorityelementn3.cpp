#include<bits/stdc++.h>
#include<climits>
using namespace std;


// vector<int> majorityelementsarrya(vector<int> arr,int n)
// {
//     int count;
//     vector<int> ls;
//     for(int i=0;i<n;i++)
//     {
//         count=0;
//         if(ls.size()==0 || ls[0]!=arr[i])
//         {
            
//             for(int j=0;j<n;j++)
//             {
//                 if (arr[i]==arr[j])
//                 {
//                     count++;
//                 }
//             }

//             if(count>(n/3))
//             {
//                 ls.push_back(arr[i]);
//             }
//         }

//         if (ls.size()==2)
//         {
//             break;
//         }
//     }
//     return ls;
// }


// vector<int> majorityelementsarrya(vector<int> arr,int n)
// {
//     map<int,int> mpp;
//     int mini=(n/3)+1;
//     vector<int> ls;
//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
    

//         if (mpp[arr[i]]==mini)
//         {
//             ls.push_back(arr[i]);
//         }
//         if (ls.size()==2)
//         {
//             break;
//         }
// }
//     return ls;
// }




//optimal solution
vector<int> majorityelementsarrya(vector<int> arr,int n)
{
    int count1=0,count2=0;
    int ele1=INT_MIN,ele2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if (count1==0 && arr[i]!=ele2){
            count1=1;
            ele1=arr[i];
        }
        else if (count2==0 && arr[i]!=ele1){
            count2=1;
            ele2=arr[i];
        }
        else if (ele1==arr[i])
            count1++;
        else if (ele2==arr[i])
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ls;
     count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        if (ele1==arr[i])
            count1++;
        if (ele2==arr[i])
            count2++;
    }
    int mini =int(n/3)+1;
    if (count1>=mini)
    
        ls.push_back(ele1);

    
    if (count2>=mini)
    
        ls.push_back(ele2);
    
    return ls;
}
int main()

{
    vector<int> arr={1,1,1,3,3,2,2,2};
  
    int n=arr.size();
    vector<int> result=majorityelementsarrya(arr,n);
    for(auto it:result)
    {
        cout<<it<<" ";
    }
    return 0;
}






// #include <bits/stdc++.h>
// using namespace std;

// vector<int> majorityElement(vector<int> v) {
//     int n = v.size(); //size of the array

//     int cnt1 = 0, cnt2 = 0; // counts
//     int el1 = INT_MIN; // element 1
//     int el2 = INT_MIN; // element 2

//     // applying the Extended Boyer Moore's Voting Algorithm:
//     for (int i = 0; i < n; i++) {
//         if (cnt1 == 0 && el2 != v[i]) {
//             cnt1 = 1;
//             el1 = v[i];
//         }
//         else if (cnt2 == 0 && el1 != v[i]) {
//             cnt2 = 1;
//             el2 = v[i];
//         }
//         else if (v[i] == el1) cnt1++;
//         else if (v[i] == el2) cnt2++;
//         else {
//             cnt1--, cnt2--;
//         }
//     }

//     vector<int> ls; // list of answers

//     // Manually check if the stored elements in
//     // el1 and el2 are the majority elements:
//     cnt1 = 0, cnt2 = 0;
//     for (int i = 0; i < n; i++) {
//         if (v[i] == el1) cnt1++;
//         if (v[i] == el2) cnt2++;
//     }

//     int mini = int(n / 3) + 1;
//     if (cnt1 >= mini) ls.push_back(el1);
//     if (cnt2 >= mini) ls.push_back(el2);

//     // Uncomment the following line
//     // if it is told to sort the answer array:
//     // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

//     return ls;
// }

// int main()
// {
//     vector<int> arr = {11, 33, 33, 11, 33, 11};
//     vector<int> ans = majorityElement(arr);
//     cout << "The majority elements are: ";
//     for (auto it : ans)
//         cout << it << " ";
//     cout << "\n";
//     return 0;
// }

