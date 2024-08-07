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
    vector<TreeNode*> solve(int st,int e){
        if(e<st){
            vector<TreeNode*>nil;
            nil.push_back(NULL);
            return nil;
        }
        vector<TreeNode*>ans;
        for(int i=st;i<=e;i++){
            //root is i
            vector<TreeNode*>left=solve(st,i-1);
            vector<TreeNode*>right=solve(i+1,e);

            for(auto l:left){
                for(auto r:right){
                    TreeNode* temp=new TreeNode(i);
                    temp->left=l;
                    temp->right=r;
                    ans.push_back(temp);
                }
            }

        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    
    }
};