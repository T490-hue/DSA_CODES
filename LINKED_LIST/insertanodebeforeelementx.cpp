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

Node* insertbeforex(vector<int>& arr,int x,Node* newnode)
{
    
    Node* head=convertarrtoLL(arr);
    if (head==NULL) return nullptr;

    if (head->data==x)
    {
        Node* temp=newnode;
        temp->next=head;
        head=temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if (temp->data==x)
        {
            prev->next=newnode;
            newnode->next=temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr={12,3,1,9,8};
    Node* newnode=new Node(10);
    Node* result=insertbeforex(arr,8,newnode);
    while(result)
    {
    cout<<result->data<<" ";
    result=result->next;
    }
    return 0;
}

