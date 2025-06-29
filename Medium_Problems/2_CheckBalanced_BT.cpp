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


int Height(Node* node){
    if(node == nullptr) return 0;
    int lf = 0;
    int rf =0;
    if(node->left != nullptr) lf = Height(node->left);
    if(lf == -1) return -1;
    if(node->right != nullptr) rf = Height(node->right);
    if(rf ==-1) return -1;
    if(abs(lf-rf) > 1)  return -1;
    return max(lf , rf) + 1;
}
bool Cheack(Node* node){
   if( Height(node) == -1) return false;
    return true;
}


int main(){
    // Manually constructing the tree:
    //        1
    //      /   \
    //     2     3
    //    /     / \
    //   4     5   6
    //        /     \
    //       7       8
    //      /
    //     9


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(9);
    root->right->right->right = new Node(8);


    cout << "B.T ";
if (Cheack(root))
    cout << "The binary tree is balanced.\n";
else
    cout << "The binary tree is NOT balanced.\n";
    cout << endl;

    // return 0;
}
