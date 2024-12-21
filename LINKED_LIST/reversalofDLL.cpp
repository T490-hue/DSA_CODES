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
// Node* reversalofDLL(vector<int>& arr)
// {
//     Node* head=convertarrtoD2L(arr);
//     if (head==NULL) return NULL;
//     stack<Node*>s;
//     Node* temp=head;
//     while(temp!=NULL)
//     {
//         s.push(temp);
//         temp=temp->next;
//     }
//     Node* top_prev=NULL;
//     Node* newhead=s.top();
//     while(!s.empty())
//     {
//         Node* topmost=s.top();
//         s.pop();
//         // top_prev->next=top;
//         topmost->prev=top_prev;

//         if (top_prev!=NULL) top_prev->next=topmost;
//         top_prev=topmost;
//     }
//     top_prev->next=NULL;
//     return newhead;
// }

Node* reversalofDLL(vector<int>& arr)
{
    Node* head=convertarrtoD2L(arr);
    if (head == NULL || head->next == NULL) {

        return head; 
    }
    
    Node* current=head;
    Node* last=NULL;
    while(current!=NULL)
    {
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    return last->prev;
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
    vector<int> arr={12,1,5,8};
    Node* head=reversalofDLL(arr);
    printnodes(head);
    return 0;
}