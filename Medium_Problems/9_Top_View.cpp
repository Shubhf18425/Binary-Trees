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


vector<int> TopView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<pair<Node* , int>> q;
    q.push({root , 0});
    map<int , int> mpp;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto level = it.second;
        if(mpp.find(it.second) == mpp.end()){
            mpp[level] = node->data;
        }
        if(node->left !=nullptr){
            q.push({node->left , level-1});
        }
        if(node->right !=nullptr){
            q.push({node->right , level+1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
int main() {
            //              1
            //           /   \
            //         2      3
            //       /   \   /   \
            //      4     5 6     7
            //     /       \     /   \
            //    8         9  11    12
            //             /     \
            //            10     13


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
    root->right->right->left->right = new Node(13);

    vector<int> res = TopView(root);

    for (const auto& vec : res) {
        cout << vec << " ";
    }

    return 0;
}
