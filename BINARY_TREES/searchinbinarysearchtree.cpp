#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return nullptr;

        if (root->val == val) return root;
        else if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

int main() {
    // Manually creating a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    // Taking input from user
    int searchValue;
    cout << "Enter the value to search in the BST: ";
    cin >> searchValue;

    // Search for the value
    TreeNode* result = sol.searchBST(root, searchValue);

    if (result != nullptr) {
        cout << "Value " << searchValue << " found in the BST." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the BST." << endl;
    }

    return 0;
}
