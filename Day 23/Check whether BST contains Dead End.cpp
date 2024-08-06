Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}
class Solution{
  public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        unordered_set<int> all_nodes;
        unordered_set<int> leaf_nodes;
        
        // Populate the sets
        populateSets(root, all_nodes, leaf_nodes);
        
        // Check for dead ends
        for (int leaf : leaf_nodes) {
            if (leaf == 1) {
                if (all_nodes.find(2) != all_nodes.end()) {
                    return true;
                }
            } else {
                if (all_nodes.find(leaf - 1) != all_nodes.end() &&
                    all_nodes.find(leaf + 1) != all_nodes.end()) {
                    return true;
                }
            }
        }
        return false;
    }
    void populateSets(Node *node, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes) {
        if (node == nullptr) {
            return;
        }
        all_nodes.insert(node->data);
        
        if (node->left == nullptr && node->right == nullptr) {
            leaf_nodes.insert(node->data);
        }
        
        populateSets(node->left, all_nodes, leaf_nodes);
        populateSets(node->right, all_nodes, leaf_nodes);
    }
};