#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // TreeNode* searchBST(TreeNode* root, TreeNode* newnode) {
    //     if (root == NULL) return nullptr;
    //     TreeNode* parent=nullptr;
    //     TreeNode* curr=root;
    //     while(curr)
    //     {
    //         parent=curr;
    //         if (curr->val>newnode->val)
    //         {
    //             curr=curr->left;
    //         }
    //         else
    //         {
    //             curr=curr->right;
    //         }
    //     }
    //     if (parent->val>newnode->val)
    //     {
    //         parent->left=newnode;
    //     }
    //     else
    //     {
    //         parent->right=newnode;
    //     }
    //     return root;
    // }


    TreeNode* searchBST(TreeNode* root,int val)
    {
        TreeNode* curr=root;
        if (curr==NULL) return new TreeNode(val);

        if (curr->val<val) 
        
            curr->right=searchBST(curr->right,val);
        
        else

            curr->left=searchBST(curr->left,val);
        
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
    cout << "Enter the value to search in the BST: ";
    cin >> searchValue;
    TreeNode* newnode=new TreeNode(searchValue);
    // Search for the value
    // TreeNode* result = sol.searchBST(root,newnode);
    TreeNode* result=sol.searchBST(root,searchValue);
    printinorder(result);
    return 0;
}
