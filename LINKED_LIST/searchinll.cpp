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

bool searchinLL(vector<int>& arr,int target)
{
    Node* temp=convertarrtoLL(arr);
    bool found=false;
    while(temp)
    {
        if (temp->data==target)
        {
            found=true;
        }
        temp=temp->next;
    }
    return found;
}


int main()
{
    vector<int> arr={12,3,1,8};
    bool result=searchinLL(arr,3);
    cout<<result;
    return 0;
}

