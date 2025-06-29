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


int Diameter(Node* node , int &maxi){
    if(node == nullptr) return 0;
    int lf = 0;
    int rf = 0;
    if(node->left != nullptr) lf = Diameter(node->left , maxi);
    if(node->right != nullptr) rf = Diameter(node->right , maxi);
    maxi = max(maxi , lf + rf);
    cout << maxi << endl;
    return max(lf , rf) + 1;
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
    // root->right->left->left->left = new Node(9);
    root->right->right->right = new Node(8);


    cout << "Diameter is ";
    int maxi = INT_MIN;
    Diameter(root  , maxi);
    cout << maxi;

    // return 0;
}
