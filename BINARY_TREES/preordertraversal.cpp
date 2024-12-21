#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=right=NULL;

    }
};

void preordertraversal(vector<int>& arr,Node* root)
{
    if (root==NULL)
        return;

    arr.push_back(root->data);
    preordertraversal(arr,root->left);
    preordertraversal(arr,root->right);
}

vector<int> preorder(Node* root)
{
    vector<int> arr;
    preordertraversal(arr,root);
    return arr;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
     root->left->right=new Node(5);
     root->right->left=new Node(6);
      root->right->right=new Node(7);

      vector<int> arr=preorder(root);

      for (int i:arr)
      {
        cout<<i;
      }
      return 0;
}