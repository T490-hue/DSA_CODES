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
void deleteanode(Node* temp)
{
    Node* back=temp->prev;
    Node* front=temp->next;

    if (front==NULL)
    {
        back->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }
    back->next=front;
    front->prev=back;
    temp->prev=temp->next=NULL;
    delete temp;
    
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
    vector<int> arr={12,3,4};
    Node* head=convertarrtoD2L(arr);
    deleteanode(head->next->next);
    printnodes(head);
    return 0;
}