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


void Iterative_PreOrder(Node* node){
    if(node == nullptr) return;
    vector<int> InOrder;
    stack<Node*> st;
    auto root = node;
    // 3 1 5 2 4 
     while(true){
        if(root != nullptr){
            st.push(root);
            root = root-> left;
        }
        else{
            if(st.empty()) break;
            root = st.top();
            st.pop();
            InOrder.push_back(root->data);
            root = root->right;
             
        }
     }
     for(auto it :  InOrder){
        cout << it << endl;
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

    cout << "Iterative_PreOrder Traversal: ";
    Iterative_PreOrder(root);
    cout << endl;

    return 0;
}
