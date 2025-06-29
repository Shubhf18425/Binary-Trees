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


vector<vector<int>> ZigZag(Node* root){
    vector<vector<int>> ans;
    if(root == nullptr){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool bl = false;
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        for(int i = 0 ; i < n ; i++){
            auto it = q.front();
            q.pop();
            level.push_back(it->data);
            if(it->left != nullptr) q.push(it->left);
            if(it->right != nullptr) q.push(it->right);
        }
        if(bl) reverse(level.begin() , level.end());
        ans.push_back(level); 
        bl = !bl;  
    }
    return ans;

}
