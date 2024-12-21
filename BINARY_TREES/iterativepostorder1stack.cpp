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
        stack<TreeNode*> s;
        vector<int> arr;
        if (root==nullptr)
            return arr;
        TreeNode* cur=root;
        while(!s.empty() || cur!=nullptr)
        {
            if (cur!=nullptr)
            {
                s.push(cur);
                cur=cur->left;
            }
            else
            {
                TreeNode* temp=s.top()->right;

                if (temp==nullptr)
                {
                    temp=s.top();
                    s.pop();
                    arr.push_back(temp->val);
                    while (!s.empty() && temp==s.top()->right)
                    {
                        temp=s.top();
                        s.pop();
                        arr.push_back(temp->val);
                    }
                }
                else
                {
                    cur=temp;
                }
            }
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
