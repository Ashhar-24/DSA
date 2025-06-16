/*
Problem: Symmetric Tree
URL: https://www.geeksforgeeks.org/problems/symmetric-tree/1
*/

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check(Node* left, Node* right){
        if(left == NULL && right == NULL) return 1;
        if(!left || !right) return 0;
        
        return ((left->data == right -> data )&& check(left->left, right->right)
                && check(left->right, right->left));
    }
    bool isSymmetric(Node* root) {
        // Code here
        return check(root->left, root->right);
    }
};