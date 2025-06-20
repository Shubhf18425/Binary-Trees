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


void Iterative_Iterative_PostOrder_2Stack(Node* node){
    if(node == nullptr) return;
    vector<int> PostOrder;
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(node);
    while(!st1.empty()){
        auto root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) st1.push(root->left);
        if(root->right != nullptr) st1.push(root->right);
    }
    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }

    
    
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

    cout << "Iterative_Iterative_PostOrder Traversal: ";
    Iterative_Iterative_PostOrder_2Stack(root);
    cout << endl;

    return 0;
}
