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

int addll(vector<int>& arr)
{
    Node* temp=convertarrtoLL(arr);
    int sum=0;
    while(temp)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}
int main()
{
    vector<int> arr={12,3,1,8};
    int sumanswer=addll(arr);
    cout<<sumanswer;
    return 0;
}

