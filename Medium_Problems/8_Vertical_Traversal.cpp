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
vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<pair<Node *, pair<int, int>>> q; // h_level , v_level;
    map<int, map<int, multiset<int>>> mpp;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        int h_level = it.second.first;
        int v_level = it.second.second;
        mpp[v_level][h_level].insert(node->data);
        if(node->left != nullptr) q.push({node->left , {h_level+1 , v_level-1}});
        if(node->right != nullptr) q.push({node->right , {h_level+1 , v_level+1}});
    }
    for(auto v_level : mpp){
        vector<int> temp;
        for(auto h_level : v_level.second){
            temp.insert(temp.end() , h_level.second.begin() , h_level.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}
int main() {
    //       1
    //     /   \
    //    2     3
    //  /  \   /  \
    // 4    5 6    7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> res = verticalTraversal(root);

    for (const auto& vec : res) {
        for (int val : vec)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
