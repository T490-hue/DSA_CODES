#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data1,Node* prev1,Node* next1)
    {
        data=data1;
        prev=prev1;
        next=next1;
    }
    Node(int data1)
    {
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
};

Node* convertarrtoD2L(vector<int>& arr)
{
    if (arr.empty()) return nullptr;
    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        temp->prev = prev; 
        prev=temp;
    }
    return head;
}
// Node* sortLL(Node* head)
// {
// if (head==NULL ||head->next==NULL) return head;
// Node* temp=head;
// int cnt0=0,cnt1=0,cnt2=0;
// while(temp!=NULL)
// {
//     if (temp->data==0) cnt0++;
//     if (temp->data==1) cnt1++;
//     if (temp->data==2) cnt2++;
//     temp=temp->next;
// }
// temp=head;

// // while(cnt0)
// // {
// //     temp->data=0;
// //     cnt0--;
// //     temp=temp->next;
// // }
// // while(cnt1)
// // {
// //     temp->data=1;
// //     cnt1--;
// //     temp=temp->next;
// // }
// // while(cnt2)
// // {
// //     temp->data=2;
// //     cnt2--;
// //     temp=temp->next;
// // }
// while(temp!=NULL)
// {
//     if (cnt0)
//     {
//         temp->data=0;
//         cnt0--;
//     }
//     else if(cnt1)
//     {
//         temp->data=1;
//         cnt1--;
//     }
//     else
//     {
//         temp->data=2;
//         cnt2--;
//     }
//     temp=temp->next;
// }

// return head;
// }
Node* sortLL(Node* head)
{
    Node* zeroD=new Node(0);
    Node* oneD=new Node(0);
    Node* twoD=new Node(0);
    Node* zero=zeroD;
    Node* one=oneD;
    Node* two=twoD;

    Node* curr=head;
    while(curr!=NULL)
    {
        if (curr->data==0)
        {
            zero->next=curr;
            zero=zero->next;
        }
        else if (curr->data==1)
        {
            one->next=curr;
            one=one->next;
        }
        else
        {
            two->next=curr;
            two=two->next;
        }
        curr=curr->next;
    }
    if (oneD->next)
    {
        zero->next=oneD->next;
    }
    else
    {
        zero->next=twoD->next;
    }
    one->next=twoD->next;
    two->next=NULL;
    head=zeroD->next;
    return head;
}
int main()
{
    vector<int> arr={1,0,1,2,0,2,1};
    Node* head=convertarrtoD2L(arr);
    Node* ans=sortLL(head);
    while(ans)
    {
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}