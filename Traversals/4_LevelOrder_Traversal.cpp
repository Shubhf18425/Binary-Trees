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


void LevelOrder(Node* node){
    if(node == nullptr) return;
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i = 0 ; i < n ; i++){
            auto top = q.front();
            q.pop();
            if(top->left != nullptr) q.push(top->left);
            if(top->right != nullptr) q.push(top->right);
            level.push_back(top->data);
        }
        ans.push_back(level);
    }
    for(int i = 0 ; i < ans.size() ; i++){
        auto xxx = ans[i];
        int nn = xxx.size();
        for(int j = 0 ; j < nn ; j++){
            cout << xxx[j] << " ";
        }
        cout << endl;
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

    cout << "LevelOrder Traversal: ";
    LevelOrder(root);
    cout << endl;

    return 0;
}
