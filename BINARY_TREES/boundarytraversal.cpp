                            
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
    bool isLeaf(Node* root){
        return !root->left && !root->right; //returns true if both left and right child not exists ,if either exists ,return false
    }
    
    void addleftboundary(Node* root,vector<int>& res)
    {
        Node* curr=root->left;
        while(curr)
        {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        
        if (curr->left)
            curr=curr->left;
        else
            curr=curr->right;
        }
    }
    void addleaves(Node* root,vector<int>& res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return ;
        }        
    if(root->left)
        addleaves(root->left,res);
    if(root->right)
        addleaves(root->right,res);
    }

    void addrightboundary(Node* root,vector<int>& res)
    {
        vector<int> temp;
        Node* curr=root->right;
        while(curr)
        {
            if(!isLeaf(curr))
                temp.push_back(curr->data);
            
            if(curr->right)
                curr=curr->right;
            else
                curr=curr->left;
    
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back(temp[i]);
        }
    }
    vector<int> printboundary(Node* root)
    {
        vector<int> res;
        if (root==nullptr)  return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        
        addleftboundary(root,res);
        addleaves(root,res);
        addrightboundary(root,res);
        return res;

    }

  
};

// Helper function to
// print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
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

    // Get the boundary traversal
    vector<int> result = solution.printboundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}
                            
                        