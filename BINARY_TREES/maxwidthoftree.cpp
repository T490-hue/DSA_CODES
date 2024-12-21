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

    int  levelordertraversal(TreeNode* root)
    {
        if (root==nullptr)
            return  0;
        
        queue<TreeNode*> q;
        q.push(root);
        int maxi=0;
        while (!q.empty())
        {
            int size=q.size();
            maxi = max(maxi, size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }

            }
            

        }
        return maxi;
    }
};


int main()

{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result=solution.levelordertraversal(root);

 cout<<result<<endl;
    return 0;
}

