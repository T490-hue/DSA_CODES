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
Node* convertarrtoLL(vector<int>& arr)
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

Node* deletetheendofll(vector<int>& arr,int k)
{
    
    Node* head=convertarrtoLL(arr);
    Node* temp=new Node(k);
    temp->next=head;
    head=temp;
    return head;
}



int main()
{
    vector<int> arr={12,3,1,8};
    Node* result=deletetheendofll(arr,4);
    while(result)
    {
    cout<<result->data<<" ";
    result=result->next;
    }
    return 0;
}

