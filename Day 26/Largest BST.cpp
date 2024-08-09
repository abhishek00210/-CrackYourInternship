class Solution {
public:
    NodeValue util(Node* node)
    {
        if(node == nullptr)
            return NodeValue(0,INT_MAX,INT_MIN);
        
        auto left = util(node->left);
        auto right = util(node->right);
        
        // node val < largest value on left side and nodeval < smallest value in the right
        if(node->data > left.maxNode and node->data < right.minNode)
        {
            int s = 1+left.size+right.size;
            int maxi = max(node->data,right.maxNode);
            int mini = min(node->data,left.minNode);
            return NodeValue(s,mini,maxi);
        }
        else
        {
            return NodeValue(max(left.size,right.size),INT_MIN,INT_MAX);
        }
    }
    int largestBst(Node *root) {
        return util(root).size;
    }
};