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

    vector<vector<int>> allordertraversal(TreeNode* root)
    {
        stack<pair<TreeNode*,int>> s;
        vector<int> pre,in,post;
        s.push({root,1});
        while (!s.empty())
        {
            auto it=s.top();
            s.pop();

            if (it.second==1)
            {
                pre.push_back(it.first->val);
                it.second++;
                s.push(it);

                if (it.first->left!=nullptr)
                    s.push({it.first->left,1});
            }

            else if (it.second==2)
            {
                in.push_back(it.first->val);
                it.second++;
                s.push(it);

                if (it.first->right!=nullptr)
                    s.push({it.first->right,1});
            }
            else
            {
                post.push_back(it.first->val);
            }
            
        }
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
    
};
void printvector(const vector<int>& arr)
{
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    
}
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
    vector<vector<int>> result=solution.allordertraversal(root);
    for (const vector<int>& arr:result)
    {
        printvector(arr);
        cout<<endl;
    }
    return 0;
}
