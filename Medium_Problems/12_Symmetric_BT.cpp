#include <bits/stdc++.h>
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
bool cheack(Node* root1 , Node* root2){
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr || root2 == nullptr) return false;
    if(root1->data != root2->data) return false;
    return cheack(root1->left , root2->right) && cheack(root1->right , root2->left);

}

bool isSymmetric(Node* root) {
    if(root == nullptr) return true;
    // if(root->left == nullptr && root->right == nullptr) return true;
    // if(root->left == nullptr || root->right == nullptr) return false;
    return cheack(root->left , root->right);

}