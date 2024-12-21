#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x): data(x),left(nullptr),right(nullptr) {}
};

class Solution{
    public:

    bool issymmetrical(Node* root)
    {
        if (!root) return true;

        return checkifsymmetrical(root->left,root->right);
        
        
    }
    bool checkifsymmetrical(Node* root1,Node* root2)
    {
        if (root1==nullptr|| root2==nullptr)    
            return root1==root2;
    
        
        return (root1->data==root2->data) && checkifsymmetrical(root1->left,root2->right) && checkifsymmetrical(root1->right,root2->left);
    }
};

int main() {
    // Creating a symmetrical binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    Solution solution;

    bool ans = solution.issymmetrical(root);
    cout << ans;  

    return 0;
}
