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

// class Solution
// {
//     public:
//     int heightofbt(TreeNode* root)
//     {
//         if (root==nullptr)
//             return 0;
//         int lh=heightofbt(root->left);
//         int rh=heightofbt(root->right);

//         return 1+max(lh,rh);
//     }
   
// };






// class Solution
// {
//     public:
//     int heightofbt(TreeNode* root)
//     {
//         if (root==nullptr)
//             return 0;
        
//         stack<pair<TreeNode*,int>> s;
//         s.push({root,1});
//         int maxDepth=0;
//         while(!s.empty())
//         {
//             auto [node,depth]=s.top();
//             s.pop();

//             maxDepth=max(maxDepth,depth);

//             if (node->left) s.push({node->left,depth+1});
//             if (node->right) s.push({node->right,depth+1});
//         }
//         return maxDepth;
//     }
   
// };

class Solution
{
    public:

    int heightofbt(TreeNode* root)
    {
        if (root==nullptr)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ht;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++) 
            {
                TreeNode* node=q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ht++;
        }
    return ht;
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
    int result=solution.heightofbt(root);

    
    cout<<result;
    return 0;
}

