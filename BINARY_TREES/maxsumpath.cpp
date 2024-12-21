#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition for a binary tree TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// // Function to calculate the overall maximum path sum
// int findMaxPath(TreeTreeNode* root,int &maxi) {
    
//     if (root==nullptr)
//         return 0;
    
//     int leftSum=findMaxPath(root->left,maxi);
//     int rightSum=findMaxPath(root->right,maxi);

//     maxi=max(maxi,leftSum+rightSum+root->val);

//     return root->val+max(leftSum,rightSum);
// }
// int maxPathSum(TreeTreeNode* root) {
//     int maxi = INT_MIN;
//     findMaxPath(root, maxi);
//     return maxi;
// }

// int main() {
//     // Example binary tree
//     TreeTreeNode* root = new TreeTreeNode(-10);
//     root->left = new TreeTreeNode(9);
//     root->right = new TreeTreeNode(20);
//     root->right->left = new TreeTreeNode(15);
//     root->right->right = new TreeTreeNode(7);

//     // Call the function to find the maximum path sum
//     cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------
//brute approach
// #include <iostream>
// #include <climits>
// using namespace std;

// // Definition for a binary tree TreeNode
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// // Function to calculate the maximum path sum from any TreeNode
// int pathSumFromTreeNode(TreeNode* root) {

//     if (root==nullptr)
//         return 0;
    
//     int left=pathSumFromTreeNode(root->left);
//     int right=pathSumFromTreeNode(root->right);

//     return root->val+ max(0,max(left,right));//to ignore the negative path
// }

// // Function to calculate the overall maximum path sum in a brute force way
// int bruteMaxPathSum(TreeNode* root) {
//     if (root==nullptr)
//         return 0;
    
//     int maxThroughRoot=root->val;
//     if (root->left) maxThroughRoot+=max(0,pathSumFromTreeNode(root->left));
//     if (root->right) maxThroughRoot+=max(0,pathSumFromTreeNode(root->right));

//     int leftMax=bruteMaxPathSum(root->left);
//     int rightMax=bruteMaxPathSum(root->right);

//     return max(maxThroughRoot,max(leftMax,rightMax));
// }


// ------------------------------------------------------------------------------------------------------------------------------------------------
int findMaxPath(TreeNode* root,int& maxi)
{
    if (root==nullptr)
        return 0;
    
    int l=findMaxPath(root->left,maxi);
    int r=findMaxPath(root->right,maxi);

    int allround=l+r+root->val;
    int singlePath=root->val+max(l,r);
    int onlyroot=root->val;

    maxi=max({maxi,allround,singlePath,onlyroot});
    return max(onlyroot,singlePath);
}

int bruteMaxPathSum(TreeNode* root)
{
    int maxi=INT_MIN;
    findMaxPath(root,maxi);
    return maxi;
}

int main() {
    // Example binary tree
    // TreeNode* root = new TreeNode(-10);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left =new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right =new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right =new TreeNode(4);
    // Call the brute force function to find the maximum path sum
    cout << "Maximum Path Sum (Brute Force): " << bruteMaxPathSum(root) << endl;

    return 0;
}
