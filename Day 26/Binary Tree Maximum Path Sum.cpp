/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxpath(TreeNode* root,int &sum)
    {
       
        if(root==NULL)
        {
            return 0;
        }
        
        
        int left=maxpath(root->left,sum);
      
        int right=maxpath(root->right,sum);
        sum=max(sum,left+right+root->val);
        return root->val+max(left,right);
     

        
    }
    int maxPathSum(TreeNode* root) {
        int sum=0;
        maxpath(root,sum);
        return sum;

    }
};