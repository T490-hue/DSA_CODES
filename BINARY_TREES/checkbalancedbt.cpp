#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int val;
    Node* left;
    Node* right;


    Node(int x): val(x),left(nullptr),right(nullptr) {}
    
};


//brute approach
class Solution
{
    public:

        bool check_balanced(Node* root) {

            if (root==nullptr)
                return true;

            int leftHeight=getHeight(root->left);
            int rightHeight=getHeight(root->right);

            if (abs(leftHeight-rightHeight)<=1 && check_balanced(root->left) && check_balanced(root->right))
            {
                return true;
            }
            return false;
        }
    int getHeight(Node* root)
    {
        if (root==nullptr)
            return 0;

        int leftht=getHeight(root->left);
        int rightht=getHeight(root->right);

        return 1+max(leftht,rightht);
    }
};

//optimal approach
class Solution
{
    public:

        bool check_balanced(Node* root) {
        // Check if the tree's height difference
        // between subtrees is less than 2
        // If not, return false; otherwise, return true
        return check_balance(root) != -1;
    }
int check_balance(Node* root)
{
  if (root==nullptr)
    return 0;

    int lh=check_balanced(root->left);
            if (lh == -1) 
            return -1;
    int rh=check_balanced(root->right);
                if (rh == -1) 
            return -1;



    if (abs(lh-rh)>1)
        return -1;
    
    return 1+max(lh,rh);
}
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.check_balanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
     

