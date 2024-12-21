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

void inordertraversal(vector<int>& arr,Node* root)
{
    if (root==NULL)
        return;
    inordertraversal(arr,root->left);
    arr.push_back(root->data);
    inordertraversal(arr,root->right);
}

vector<int> inorder(Node* root)
{
    vector<int> arr;
    inordertraversal(arr,root);
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

      vector<int> arr=inorder(root);

      for (int i:arr)
      {
        cout<<i;
      }
      return 0;
}