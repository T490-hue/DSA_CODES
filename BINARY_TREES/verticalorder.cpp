// #include<bits/stdc++.h>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class Solution
// {
//     public:
//     vector<vector<int>> verticalorder(Node* root)
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
//     for(auto level: result){
//         for(auto node: level){
//             cout << node << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
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

//     // Get the Vertical traversal
//     vector<vector<int>> verticalTraversal =
//                     solution.verticalorder(root);

//     // Print the result
//     cout << "Vertical Traversal: ";
//     printResult(verticalTraversal);

//     return 0;
// }
                    



//brute-Perform a pre-order traversal (DFS) of the binary tree.
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// A structure to store node info (vertical, level, value)
struct NodeInfo {
    int vertical;
    int level;
    int value;
    NodeInfo(int v, int l, int val) : vertical(v), level(l), value(val) {}
};

class Solution
{
    public:
    void dfs(Node* node,int vertical,int level,vector<NodeInfo>& nodelist)
    {
        if (node==nullptr)
            return;
        
        nodelist.push_back(NodeInfo(vertical,level,node->data));
        dfs(node->left,vertical-1,level+1,nodelist);
        dfs(node->right,vertical+1,level+1,nodelist);

    }
    vector<vector<int>> verticalorder(Node* root)
    {
        vector<NodeInfo> nodelist;
        vector<vector<int>> ans;
        dfs(root,0,0,nodelist);

        sort(nodelist.begin(),nodelist.end(),[](NodeInfo&a,NodeInfo&b)
        {
            if (a.vertical!=b.vertical) return a.vertical<b.vertical;
            if (a.level!=b.level) return a.level<b.level;
            return a.value<b.value;
        });
        map<int,vector<int>> sortednodes;
        for(auto& nodeinfo:nodelist)
        {
            sortednodes[nodeinfo.vertical].push_back(nodeinfo.value);
        }
        for(auto& p:sortednodes)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
    Solution solution;

    // Get the vertical traversal
    vector<vector<int>> verticalTraversal = solution.verticalorder(root);

    // Print the result
    cout << "Brute Force Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}
