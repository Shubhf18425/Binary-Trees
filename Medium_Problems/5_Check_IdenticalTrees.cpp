#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


int MaxPathHelper(Node* node, int &res) {
    if (node == nullptr) return 0;
    int lf = std::max(0, MaxPathHelper(node->left,  res));
    int rf = std::max(0, MaxPathHelper(node->right, res));
    
    res = std::max(res, node->data + lf + rf);
    
    return node->data + std::max(lf, rf);
}

int MaxPath(Node* root) {
    int res = INT_MIN;                
    MaxPathHelper(root, res);
    return res;
}

int main(){
    // Manually constructing the tree:
    //      10
    //     /  \
    //    2    10
    //   / \     \
    //  20  1    -25
    //          /   \
    //         3     4



Node* root = new Node(10);
root->left = new Node(2);
root->right = new Node(10);
root->left->left = new Node(20);
root->left->right = new Node(1);
root->right->right = new Node(-25);
root->right->right->left = new Node(3);
root->right->right->right = new Node(4);



    cout << "MAX PATH SUM IS  ";
    int maxi = MaxPath(root);
    cout << maxi;

    // return 0;
}
