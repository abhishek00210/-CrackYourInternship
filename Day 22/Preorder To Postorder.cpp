class Solution {
  public:
    Node* insertNode(Node* root, int data) {
        if(root) {
            if(data < root->data) 
                root->left = insertNode(root->left, data);
            else
                root->right = insertNode(root->right, data);
        } else{
            return newNode(data);
        }
        return root;
    }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        Node *root;
        for(int i = 0; i < size; i++) {
            root = insertNode(root, pre[i]);
        }
        return root;
    }
};