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

    vector<vector<int>>  levelordertraversal(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root==nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size=q.size();
            vector<int> level;
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
                level.push_back(node->val);

            }
            

            ans.push_back(level);
        }
        return ans;
    }
};

void printvector(const vector<int>& arr)
{
    for(int i:arr)
    {
        cout<<i;
    }
}

int main()

{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<vector<int>> result=solution.levelordertraversal(root);

    for(const vector<int>& arr:result)
    {
        printvector(arr);
    }
    return 0;
}

