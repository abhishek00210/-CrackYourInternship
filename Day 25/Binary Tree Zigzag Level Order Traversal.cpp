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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        bool LeftToRight=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<int> reuslt(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* frontnode=q.front();
                q.pop();

                int index=LeftToRight ? i : size-i-1;
                

                reuslt[index]=frontnode->val;


                if(frontnode->left!=NULL)
                {
                    q.push(frontnode->left);

                }
                if(frontnode->right!=NULL)
                {
                    q.push(frontnode->right);
                }
            }
        LeftToRight=!LeftToRight;

       ans.push_back(reuslt);
            
        }
        return ans;


    }
};