#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// class Solution
// {
//     public:
//     vector<vector<int>> bottomview(Node* root)
//     {
//         map<int, map<int, multiset<int>>> nodes;  // first int is vertical, second int is level, multiset is node data
//         queue<pair<Node*, pair<int, int>>> todo;
//         todo.push({root,{0,0}});
//         while(!todo.empty())
//         {
//             auto p=todo.front();
//             todo.pop();
//             Node* node=p.first;
//             int x=p.second.first;//vertical
//             int y=p.second.second;//level
//             nodes[x][y].insert(node->data);
//             if (node->left)
//             {
//                 todo.push({node->left,{x-1,y+1}});
//             }
//             if (node->right)
//             {
//                 todo.push({node->right,{x+1,y+1}});
//             }
//         }
//             vector<vector<int>> ans;
//             for(auto p:nodes) //iterates through the vertical p is basically the enitre thing -map<int,map<int,multiset<int>>> nodes
//             {
//                 vector<int> col;
//                 for(auto q:p.second)//iterates through level and node -map<int,multiset<int>>> 
//                 {
//                     col.insert(col.end(),q.second.begin(),q.second.end());
//                 }
//                 ans.push_back(col);
//             }

        
//             return ans;
//     }
    

// };

// void printResult(const vector<vector<int>>& result) {


//     for(int row=0;row<result.size();row++)
//     {
//         int m=result[row].size();
//         cout<<result[row][m-1]<<" ";
//     }

// }

// --------------------------------------------------------------------------------------------------------------------------------------------------------
//using a normal queue and map
// class Solution
// {
//     public:
//     vector<int> bottomview(Node* root)
//     {
//         map<int,int> mpp;
//         queue<pair<Node*,int>> todo;
//         todo.push({root,0});
//         vector<int> ans;
//         while(!todo.empty()){
//             auto p=todo.front();
//             todo.pop();
//             Node* node=p.first;
//             int line=p.second;
//             mpp[line]=node->data;
//             if(node->left)
//             {
//                 todo.push({node->left,line-1});
//             }
//             if (node->right)
//             {
//                 todo.push({node->right,line+1});
//             }
//         }
//         for(auto it:mpp)
//         {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
// void printResult(vector<int>& ans)
// {
//     for(auto it:ans)
//     {
//         cout<<it;
//     }
// }
// --------------------------------------------------------------------------------------------------------------------------------------------------------
struct NodeInfo{

int val;
int line;
};

class Solution
{
    public:
    void dfs(Node* root,int line,vector<NodeInfo>& nodelist)
    {
        if (root==nullptr)  return;
    nodelist.push_back(NodeInfo{root->data,line});
    if (root->left) dfs(root->left,line-1,nodelist);
    if(root->right) dfs(root->right,line+1,nodelist);
    }
    vector<int> bottomview(Node* root)
    {
        map<int,int> mpp;
        vector<int> ans;
        vector<NodeInfo> nodelist;
        dfs(root,0,nodelist);
        for(auto it:nodelist)
        {
            mpp[it.line]=it.val;
        }
        for(auto m:mpp)
        {
            ans.push_back(m.second);
        }
        return ans;
    }
};
void printResult(vector<int>& ans)
{
    for(auto it:ans)
    {
        cout<<it;
    }
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->left->right->left=new Node(8);
    root->right->left->right=new Node(9);



    Solution solution;

    // Get the Vertical traversal
    // vector<vector<int>> result =
    //                 solution.bottomview(root);
    vector<int> result=solution.bottomview(root);

    // Print the result
    cout << "bottom view: ";
    printResult(result);

    return 0;
}
                    
