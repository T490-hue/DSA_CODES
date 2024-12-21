#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x):val(x),left(nullptr),right(nullptr) {}
};

// bool isidenticaltrees(Node* root1,Node* root2)
// {
//     if (root1==nullptr && root2==nullptr)
//         return true;
//     if (root1==nullptr || root2==nullptr)
//         return false;
    
//     return (root1->val==root2->val && isidenticaltrees(root1->left,root2->left) && isidenticaltrees(root1->right,root2->right));
   
// }

//brute aproach taking space for the stack
// bool isIdenticalTrees(Node* root1, Node* root2) {
   
//    if (root1==nullptr && root2==nullptr)
//     return true;
//     if (root1==nullptr || root2==nullptr)
//     return false;

//     stack<Node*> s1;
//     stack<Node*> s2;

//     s1.push(root1);
//     s2.push(root2);

//     while(!s1.empty() && !s2.empty())
//     {
//         Node* n1=s1.top();
//         Node* n2=s2.top();
//         s1.pop();
//         s2.pop();

//         if (n1->val!=n2->val)
//             return false;
        
//         if (n1->left && n2->left)
//         {
//             s1.push(n1->left);
//             s2.push(n2->left);
//         }
//         else if (n1->left || n2->left)
//             return false;

//         if (n1->right && n2->right)
//         {
//             s1.push(n1->right);
//             s2.push(n2->right);
//         }
//         else if (n1->right || n2->right)
//             return false;

//     }
//     return s1.empty() && s2.empty();
// }

//using queues
bool isIdenticalTrees(Node* root1, Node* root2) {
   
   if (root1==nullptr && root2==nullptr)
    return true;
    if (root1==nullptr || root2==nullptr)
    return false;

    queue<Node*> s1;
    queue<Node*> s2;

    s1.push(root1);
    s2.push(root2);

    while(!s1.empty() && !s2.empty())
    {
        Node* n1=s1.front();
        Node* n2=s2.front();
        s1.pop();
        s2.pop();

        if (n1->val!=n2->val)
            return false;
        
        if (n1->left && n2->left)
        {
            s1.push(n1->left);
            s2.push(n2->left);
        }
        else if (n1->left || n2->left)
            return false;

        if (n1->right && n2->right)
        {
            s1.push(n1->right);
            s2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;

    }
    return s1.empty() && s2.empty();
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    bool answer = isIdenticalTrees(root1, root2);
    cout << (answer ? "The trees are identical." : "The trees are not identical.") << endl;
    return 0;

}