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

Node* deletebasedonvalue(vector<int>& arr,int k)
{
    
    Node* head=convertarrtoLL(arr);
    if (head==NULL) return nullptr;
    Node* temp=head;
    Node* prev=NULL;
    if (head->data==k)
    {
        head=head->next;
        free(temp);
        return head;
    }
    while(temp!=NULL)
    {
        if (temp->data ==k)
        {
            prev->next=prev->next->next;
            free(temp);
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
    Node* result=deletebasedonvalue(arr,12);
    while(result)
    {
    cout<<result->data<<" ";
    result=result->next;
    }
    return 0;
}

