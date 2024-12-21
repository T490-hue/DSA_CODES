#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
Node* convertoLL(vector<int>& arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int countll(vector<int> arr)
{
    Node* temp=convertoLL(arr);
    int cnt=0;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    vector<int> arr={12,3,1,8};
    int  y=countll(arr);
    cout<<endl;
    cout<<y;
    return 0;
}

