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
Node* deletionD2Lhead(Node* head)
{
    
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;

}
Node* deletionD2Ltail(Node* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return NULL;
    }
    
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    Node* newTail = temp->prev;
    newTail->next =NULL;
    temp->prev=NULL;
    delete temp;  
    return head;
}
Node* deletionD2Lkthnode(vector<int>& arr,int k) {
    Node* head = convertarrtoD2L(arr);
    

    if (head == nullptr ) return NULL;
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if (cnt==k)
        {
            break;
        }
        temp=temp->next;
    }
    Node* back=temp->prev;
    Node* front=temp->next;
    if (front==NULL && back==NULL) return NULL;

    else if (front==NULL) deletionD2Ltail(temp);

    else if (back==NULL) deletionD2Lhead(temp);
    else{
    back->next=front;
    front->prev=back;
    temp->prev=temp->next=NULL;
    delete temp;
    return head;
    }
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
    vector<int> arr={12,3,4,7,5,1};
    Node* head=deletionD2Lkthnode(arr,1);
    printnodes(head);
    return 0;
}