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
    vector<int> InOrder;
    vector<int> PreOrder;
    stack<pair<Node* , int>>  st;
    st.push({node , 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            PreOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != nullptr){
                st.push({it.first->left , 1});
            }
        }
        else if(it.second == 2){
            InOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != nullptr){
                st.push({it.first->right , 1});
            }
        }
        else{
            PostOrder.push_back(it.first->data);
        }
    }
    for(auto it : PreOrder){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : InOrder){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : PostOrder){
        cout << it << " ";
    }
    cout << endl;  
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
