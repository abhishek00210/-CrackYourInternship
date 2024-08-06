class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==NULL) return root2; // If root1 is null, return root2
        if (root2==NULL) return root1; // If root2 is null, return root1
        // Merge the values of root1 and root2 and create a new node
        TreeNode* merged = new TreeNode(root1->val + root2->val);
        // Recursively merge the left children
        merged->left = mergeTrees(root1->left, root2->left);
        // Recursively merge the right children
        merged->right = mergeTrees(root1->right, root2->right);

        return merged; 
    }
};