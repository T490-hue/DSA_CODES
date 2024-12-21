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

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    Solution sol;

    vector<int> result=sol.bottomview(root);
    printResult(result);


    return 0;
}




