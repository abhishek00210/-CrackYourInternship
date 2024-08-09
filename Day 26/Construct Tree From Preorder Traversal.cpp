Node* constructTreeUtil(int pre[], char preLN[], int& index, int n) {
        // Base case
        if (index >= n) return NULL;

        // Allocate memory for this node and increment index for subsequent nodes
        Node* node = new Node(pre[index]);

        // If this node is a leaf, return the node
        if (preLN[index] == 'L') {
            index++;
            return node;
        }

        // If this node is not a leaf, then recursively build the left and right subtrees
        index++;
        node->left = constructTreeUtil(pre, preLN, index, n);
        node->right = constructTreeUtil(pre, preLN, index, n);

        return node;
    }
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index=0;
    return constructTreeUtil(pre,preLN,index,n);
}