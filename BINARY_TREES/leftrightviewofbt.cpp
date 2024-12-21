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
//     vector<vector<int>> lrview(Node* root)
//     {
//    vector<vector<int>> ans;
//    queue<Node*> todo;
//    todo.push(root);
//    while(!todo.empty())
//    {
//     vector<int> level;
//     int size=todo.size();
//     for(int i=0;i<size;i++)
//     {
//         Node* node=todo.front();
//         todo.pop();
//         if(node->left) todo.push(node->left);
//         if (node->right) todo.push(node->right);
//         level.push_back(node->data);
//     }
//     ans.push_back(level);
//    }
// return ans;
//     }

// };

// void printResult(const vector<vector<int>>& result) {

//     vector<int> right;
//     vector<int> left;
//     for(auto it:result)
//     {
//         for(auto i:it)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<result.size();i++)
//     {
//         int m=result[i].size();
//         left.push_back(result[i][0]);
//         right.push_back(result[i][m-1]);
//     }
//     for(auto l:left)
//     cout<<l<<" ";
//     cout<<endl;
//     for(auto r:right)
//     cout<<r<<" ";
// }
// int main() {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->right = new Node(10);
//     root->left->left->right = new Node(5);
//     root->left->left->right->right = new Node(6);
//     root->right = new Node(3);
//     root->right->right = new Node(10);
//     root->right->left = new Node(9);

//     Solution solution;

//     vector<vector<int>> result=solution.lrview(root);
//     printResult(result);

//     return 0;
// }









class Solution
{
    public:
    void dfs_rightview(Node* node,int level,vector<int>& rightview)
    {
        if (node==nullptr) return;

        if (level==rightview.size())
            rightview.push_back(node->data);
        
        dfs_rightview(node->right,level+1,rightview);
        dfs_rightview(node->left,level+1,rightview);
    }
    void dfs_leftview(Node* node,int level,vector<int>& leftview)
    {
                if (node==nullptr) return;

        if (level==leftview.size())
            leftview.push_back(node->data);
        
        dfs_leftview(node->left,level+1,leftview);
        dfs_leftview(node->right,level+1,leftview);

    }
void printresults(Node* root)
{
    vector<int> leftview;
    vector<int> rightview;
    dfs_rightview(root,0,rightview);
    dfs_leftview(root,0,leftview);
    for(auto it:leftview)
    cout<<it;
    cout<<endl;
    for(auto it:rightview)
    cout<<it;
    cout<<endl;

}

};


int main() {
    // Creating a sample binary tree
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

    solution.printresults(root);

    return 0;
}


