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
void recursion(Node* root , int level , vector<int> & ans){
    if(root == nullptr) return ;
    if(level == ans.size()) ans.push_back(root->data);
    recursion(root->right , level+1 , ans); // for left view just swap line number 15 and 16
    recursion(root->left , level+1 , ans);
}

vector<int> BottomView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    recursion(root , 0 , ans);
}
int main() {
            //              1
            //           /   \
            //         2      3
            //       /   \   /   \
            //      4     5 6     7
            //     /       \     /   \
            //    8         9  11    12
            //             /     
            //            10     


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);
    root->right->right->left->left = new Node(10);

    vector<int> res = BottomView(root);

    for (const auto& vec : res) {
        cout << vec << " ";
    }

    return 0;
}
