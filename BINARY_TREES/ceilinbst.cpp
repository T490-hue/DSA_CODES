#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
     int floor(TreeNode* root, int x) {
        
        int floor=-1;
        while(root)
        {
            if (root->data==x) {
                floor=root->data;
                return floor;
            }
            else if (root->data>x)
            {
                root=root->left;
            }
            else
            {
                floor=root->data;
                root=root->right;
            }
        }
        return floor;
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
    int ceil=-1;
    // Search for the value
    int result = sol.floor(root, searchValue);

    cout<<result;

    return 0;
}
