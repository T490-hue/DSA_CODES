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

Node* addtwolinkedlist(Node* l1,Node* l2)
{
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum=0;
        if (l1!=NULL) 
        {
            sum=sum+l1->data;
            l1=l1->next;
        }
        if (l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newnode=new Node(sum%10);
        temp->next=newnode;
        temp=temp->next;
    }
    return dummy->next;
}
void printresult(Node* result)
{
    while(result!=NULL)
    {
        cout<<result->data<<" ";
        result=result->next;
    }
}
int main()
{
    vector<int> arr1={2,4,3};
    vector<int> arr2={5,6,4};

    Node* l1=convertarrtoD2L(arr1);
    Node* l2=convertarrtoD2L(arr2);
    Node* result=addtwolinkedlist(l1,l2);
    printresult(result);
    return 0;
}