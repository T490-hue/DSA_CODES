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
Node* deletionD2Lhead(vector<int>& arr)
{
    Node* head=convertarrtoD2L(arr);
    if (head==NULL || head->next==NULL) return NULL;
   
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    free(temp);
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
    vector<int> arr={12};
    Node* head=deletionD2Lhead(arr);
    printnodes(head);
    return 0;
}