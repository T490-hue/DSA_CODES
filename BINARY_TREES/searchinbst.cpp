#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
     TreeNode* insertnodeinbst(TreeNode* root, TreeNode* newnode) 
     {
        
        TreeNode* node=new TreeNode(-1);
        while(root){
        if (root->data>newnode->data)
        {
            node=root;
            root=root->left;
        }
        else
        {
            node=root;
            root=root->right;
        }
        }
        if (node->data>newnode->data)
        {
            node->left=newnode;
        }
        else
        {
            node->right=newnode;
        }
        return root;
     }

};

int main() {
    // Manually creating a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    TreeNode* newnode=new Node(5);
    TreeNode* root=insertnodeinbst(root,newnode);
    while(root)
    {
        cout<<root->data;
        cout<<endl;
    }

    return 0;
}
