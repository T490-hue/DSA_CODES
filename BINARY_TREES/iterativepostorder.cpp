#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

class Solution{
    public:

    vector<int> postordertraversal(TreeNode* root)
    {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> arr;
        if (root==nullptr)
            return arr;
        s1.push(root);
        while (!s1.empty())
        {
            root=s1.top();
            s1.pop();
            s2.push(root);
            if (root->left!=nullptr)
                s1.push(root->left);
            if (root->right!=nullptr)
                s1.push(root->right);

        }
        while(!s2.empty())
        {
            arr.push_back(s2.top()->val);
            s2.pop();
        }
        return arr;
    
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    Solution solution;
    vector<int> result=solution.postordertraversal(root);
    for (int num:result)
    {
        cout<<num<<" ";
    }
    return 0;
}