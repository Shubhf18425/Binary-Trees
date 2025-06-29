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
 bool isleafnode(Node* root){
    if(root->right == nullptr && root->left == nullptr) return true;
    return false;
 }
void left_Traversal(Node* root , vector<int> &ans){
    Node* curr = root->left;
    while(curr != nullptr){
        if(!isleafnode(curr)) ans.push_back(curr->data);
        if(curr->left != nullptr) curr = curr->left;
        else curr = curr->right;
    }
}

void bottom_Traversal(Node* root , vector<int> &ans){
        if (root == nullptr) return;  // add nullptr check

     if(isleafnode(root)){ ans.push_back(root->data);return;}
    if(root->left != nullptr) bottom_Traversal(root->left , ans);
     if(root->right != nullptr)bottom_Traversal(root->right , ans);
}


void right_Traversal(Node* root , vector<int> &ans){
    vector<int> temp;
    Node* curr = root->right;
    while(curr != nullptr){
        if(!isleafnode(curr)) temp.push_back(curr->data);
        
        if(curr->right != nullptr) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin() , temp.end());
    for(int i = 0 ; i < temp.size() ; i++){
        ans.push_back(temp[i]);
    }
}

vector<int> Boundary_Traversal(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    if (!isleafnode(root))  // fix: avoid duplicate if root is a leaf
        ans.push_back(root->data);
    left_Traversal(root , ans);
    bottom_Traversal(root , ans);
    right_Traversal(root , ans);
    return ans;

}
int main() {
    /*  Example tree
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
                     /
                    8
       Boundary traversal should be: 1 2 4 5 8 7 3
    */
    Node* root = new Node(1);
    root->left            = new Node(2);
    root->right           = new Node(3);
    root->left->left      = new Node(4);
    root->left->right     = new Node(5);
    root->right->left     = new Node(6);
    root->right->right    = new Node(7);
    root->right->right->left = new Node(8);

    vector<int> res = Boundary_Traversal(root);
    cout << "Boundary traversal: ";
    for (int x : res) cout << x << ' ';
    cout << '\n';

    /* (Optional) clean-up nodes here … */
    return 0;
}