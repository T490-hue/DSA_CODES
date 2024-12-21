#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findMin(TreeNode* root)
    {
        while(root!=NULL && root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {


        if (root==NULL) return root;

        else if (root->val<key)
            root->right=deleteNode(root->right,key);
        else  if (root->val>key)
            root->left=deleteNode(root->left,key);
        else{
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if (root->left==NULL)
        {
            TreeNode* temp=root;
            root=root->right;
            delete temp;
        }
        else if (root->right==NULL)
        {
            TreeNode* temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            TreeNode* temp=findMin(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }
        }
        return root;
    }
};

void printinorder(TreeNode* root)
{
    if (root==NULL)
     return ;
    
    printinorder(root->left);
    cout<<root->val;
    printinorder(root->right);
}

int main() {
    // Manually creating a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    // Taking input from user
    int searchValue;
    cout << "Enter the value to delete in the BST: ";
    cin >> searchValue;
    TreeNode* newnode=new TreeNode(searchValue);
    // Search for the value
    // TreeNode* result = sol.searchBST(root,newnode);
    TreeNode* result=sol.deleteNode(root,searchValue);
    printinorder(result);
    return 0;
}
