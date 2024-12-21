#include<bits/stdc++.h>
using namespace std;


struct TreeNode

{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right) {}
};

class Solution {
public:
    int maxwidth(TreeNode* root) {    
        if (root==nullptr)
            return 0;

        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int ans=0;
        while (!q.empty())
        {
            int size=q.size();
            unsigned long long mmin=q.front().second;
            unsigned long long first, last;
            
            for(int i=0;i<size;i++)
            {
                unsigned long long cur_id=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if (i==0) first=cur_id;
                if (i==size-1) last=cur_id;
             

                if (node->left) q.push({node->left,cur_id*2+1});
                if (node->right) q.push({node->right,cur_id*2+2});
            }
            ans=max(ans,static_cast<int>(last-first+1));
        }
        return ans;

    }
    
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int maxWidth = sol.maxwidth(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}
                            