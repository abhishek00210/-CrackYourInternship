/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int x=node2root(root,target,k);
        return res;
    }
    int node2root(TreeNode* root, TreeNode* target, int k)
    {
        if(root == NULL)
            return -1;
        if(target->val == root->val)
        {
            kdown(root, NULL, k);
            return 1;
        }
        int l = node2root(root->left, target, k);
        if(l != -1)
        {
            kdown(root, root->left, k - l);
            return l + 1;
        }
        int r = node2root(root->right, target, k);
        if(r != -1)
        {
            kdown(root, root->right, k - r);
            return r + 1;
        }
        return -1;
    }
    void kdown(TreeNode* root,TreeNode* block,int k)
    {
        if(root == NULL || root == block || k < 0)
            return;
        if(k == 0)
        {
            res.push_back(root->val);
            return;
        }
        kdown(root->left, block, k-1);
        kdown(root->right, block, k-1);
        
    }
};