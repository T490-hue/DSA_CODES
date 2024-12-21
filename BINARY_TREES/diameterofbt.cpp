#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x):val(x),left(nullptr),right(nullptr) {}
};

// class Solution
// {
//     public:

//     int diameter=0;
//     int calculateHeight(Node* root)
//     {
//         if (root==nullptr)
//             return 0;

//         int lh=calculateHeight(root->left);
//         int rh=calculateHeight(root->right);

//         diameter=max(diameter,lh+rh);

//         return 1+max(lh,rh);
//     }
//     int diameterofbt(Node* root)
//     {
//         calculateHeight(root);

//         return diameter;
//     }

// };

class Solution
{
    public:

    int calculateHeight(Node* root)
    {
        if (root==nullptr)
            return 0;

        int lh=calculateHeight(root->left);
        int rh=calculateHeight(root->right);

        return 1+max(lh,rh);
        
    }
    int diameterofbt(Node* root)
    {
        if (root==nullptr)
            return 0;
        int lh=calculateHeight(root->left);
        int rh=calculateHeight(root->right);

        int diameter=lh+rh;

        int ld=diameterofbt(root->left);
        int rd=diameterofbt(root->right);

        return max(diameter,max(ld,rd));
    }

};


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterofbt(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}

