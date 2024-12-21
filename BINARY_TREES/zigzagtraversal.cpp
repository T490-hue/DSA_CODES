                            
// #include <iostream>
// #include <algorithm>
// #include <climits>
// #include <queue>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
    
//     vector<vector<int>> ZigZagLevelOrder(Node* root)
//     {
//         vector<vector<int>> result;

//         queue<Node*> q;
//         q.push(root);
//         bool leftToRight=true;

//         while(!q.empty())
//         {
//             int size=q.size();
//             vector<int> row(size);

//             for(int i=0;i<size;i++)
//             {
//                 Node* node=q.front();
//                 q.pop();
//                 int index=leftToRight? i:(size-1-i);
//                 row[index]=node->data;

//                 if(node->left)
//                 q.push(node->left);
//                 if(node->right)
//                 q.push(node->right);
//             }
//             leftToRight=!leftToRight;
//             result.push_back(row);
//         }

//     return result;
//     }
// };



// void printResult(const vector<vector<int>>& result) {
//     for (const auto& row : result) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     Solution solution;

//     vector<vector<int>> result = solution.ZigZagLevelOrder(root);

//     printResult(result);

//     return 0;
// }
                            
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> ZigZagLevelOrder(Node* root) {
        vector<vector<int>> result;
        DFS(root, 0, result);
        return result;
    }

    void DFS(Node* node, int level, vector<vector<int>>& result) 
    {
        if (node==nullptr) return ;

        if (level>=result.size())
            result.push_back({});

        if (level%2==0) //left to right
        {
            result[level].push_back(node->data);
        }
        else
        {
            result[level].insert(result[level].begin(),node->data);
        }

        DFS(node->left,level+1,result);
        DFS(node->right,level+1,result);
    }
        
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);
    printResult(result);
    return 0;
}
