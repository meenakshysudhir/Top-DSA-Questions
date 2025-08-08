//You are given a binary tree, the task is to find out the length of the longest path which contains nodes with the exact same value. 
//It is not necessary for the path to pass through the root of the binary tree.Between two nodes,the length of the path can be defined
// as the number of edges contained between them.

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
Node* buildTree(const vector<int>& input){
    if(input.empty() || input[0] == -1) return nullptr;
    Node* root = new Node(input[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < input.size()){
        Node* node = q.front();
        // cout << node -> val << " ";
        q.pop();
        if(input[i] != -1){
            node -> lc = new Node(input[i]);
            q.push(node -> lc);
        }
        i++;
        if(i >= input.size()) break;
        if(input[i] != -1){
            node -> rc = new Node(input[i]);
            q.push(node -> rc);
        }
        i++;
    }
    return root;
    
}
int maxLen = INT_MIN;
int dfs(Node* root){
    //using postorder DFS 
    if(!root) return 0;

    int left = dfs(root -> lc);
    int right = dfs(root -> rc);

    int leftPath = 0, rightPath = 0;
    if(root -> lc && root -> val == root -> lc -> val){
        leftPath = left +1;
    }
    if(root -> rc && root ->val == root -> rc -> val){
        rightPath = right + 1;
    }
    maxLen = max(maxLen,leftPath + rightPath);
    return max(leftPath,rightPath);
     
}
int main(void){
    vector<int> input = { 1,4,5,4,4,-1, 5, -1, -1, -1, -1, -1, -1};
    Node* root = buildTree(input);
    int hi = dfs(root);
    cout  << maxLen << endl;
}