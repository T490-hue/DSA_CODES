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
Node* insertbeforehead(Node* head,Node* newnode)
{
if (head==NULL) return newnode;
newnode->next=head;
head->prev=newnode;
head=newnode;
return head;
}

Node* insertbeforetail(vector<int>& arr,int val)
{

Node* head=convertarrtoD2L(arr);
Node* temp=head;
Node* newnode=new Node(val);
if (head==NULL) return newnode;

if (head->next==NULL) return insertbeforehead(head,newnode);
while(temp->next!=NULL)
{
    temp=temp->next;
}
Node* back=temp->prev;
back->next=newnode;
newnode->prev=back;
newnode->next=temp;
temp->prev=newnode;
return head;
}

void printnodes(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    vector<int> arr={12,13,14};
    Node* head=insertbeforetail(arr,10);
    printnodes(head);
    return 0;
}