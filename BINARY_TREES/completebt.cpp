#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0),left(nullptr),right(nullptr) {}

    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right) {}
};

class Solution
{
    public:

  bool completebt(TreeNode* root)
  {
    if (root==nullptr)
        return 0;
    queue<TreeNode*> q;
    bool foundtrue=false;
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        
        for(int i=0;i<size;i++)
        {
            TreeNode* node=q.front();
            q.pop();
            if (node==nullptr)
            {
                foundtrue=true;
            }
            else
            {
                if (foundtrue)
                {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
            
    }
  }
  return true;
  }
};



int main()

{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool result=solution.completebt(root);
cout<<result;
    return 0;
}

