                            
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
vector<int> getPreorder(TreeNode* root) {
    vector<int> preorder; // Stores the result
    TreeNode* cur = root;

    while (cur != NULL) {
        if (cur->left == NULL) {
            preorder.push_back(cur->val); // **Add before visiting the left subtree**
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = cur; // Create the thread
                preorder.push_back(cur->val); // **Add the current node before left subtree**
                cur = cur->left;
            } else {
                prev->right = NULL; // Remove the thread
                cur = cur->right;
            }
        }
    }

    return preorder;
}
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    
    vector<int> inorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traversal: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
                            
                        
