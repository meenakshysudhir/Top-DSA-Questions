// to find the diameter of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* lc;
    Node* rc;

    Node(int key){
        val = key;
        lc = rc = nullptr;
    }
};
int findDiameter(Node* root){
    if(!root) return 0;

    return 1 + max(findDiameter(root ->lc),findDiameter(root->rc));
}
int main(void){
    Node * node = new Node(1);
    node -> lc = new Node(2);
    node -> rc = new Node(3);
    node -> lc -> lc = new Node(4);
    node -> lc -> lc -> lc = new Node(5);
    cout << "Diameter : " << findDiameter(node) << endl;
}