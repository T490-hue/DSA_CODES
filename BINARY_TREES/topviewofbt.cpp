#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x):val(x),left(nullptr),right(nullptr) {}
};


// class Solution{
//     public:
//     vector<int> topview(Node* root)
//     {
//         vector<int> ans;
//         queue<pair<Node*,int>> q;
//         map<int,int> mpp;

//         q.push({root,0});
//         while(!q.empty())
//         {
//             auto p=q.front();
//             q.pop();
//             Node* node=p.first;
//             int line=p.second;
//             if (mpp.find(line)==mpp.end()) mpp[line]=node->val;
//             if (node->left)
//             {
//                 q.push({node->left,line-1});
//             }
//             if (node->right)
//             {
//                 q.push({node->right,line+1});
//             }

//         }
//         for(auto& p:mpp)
//         {
//             ans.push_back(p.second);
//         }
//         return ans;
//     }
// };
struct NodeInfo
{
    int data;
    int line;
    NodeInfo(int d,int l):data(d),line(l) {}
};
class Solution{
    public:
    void dfs(Node* node,int line,vector<NodeInfo>& nodelist)
    {
        if (node==nullptr) 
            return;

        nodelist.push_back(NodeInfo(node->val,line));
        if (node->left)
        {
            dfs(node->left,line-1,nodelist);
        }
        if (node->right)
        {
            dfs(node->right,line+1,nodelist);
        }
    }
    vector<int> topview(Node* root)
    {
        vector<int> ans;
        vector<NodeInfo> nodelist;
        dfs(root,0,nodelist);
         
        map<int,int> topview;
        for(auto& p:nodelist)
        {
            if (topview.find(p.line)==topview.end())
            {
                topview[p.line]=p.data;
            }

        }
        for(auto& p:topview)
        {
            ans.push_back(p.second);
        }
    return ans;

    }
};

void printtopview(const vector<int>& ans)
{
    for(auto p:ans)
    {
        cout<<p<<" ";
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> result=solution.topview(root);
    printtopview(result);
    return 0;
}

