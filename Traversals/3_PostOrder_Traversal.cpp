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


void PostOrder(Node* node){
    if(node == nullptr) return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";

}
int main(){
     // Manually constructing the tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "PostOrder Traversal: ";
    PostOrder(root);
    cout << endl;

    return 0;
}
