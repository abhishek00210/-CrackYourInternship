class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      if(root==NULL){
          return 0;
      }
      int count=0;
      if(root->data > l){
          count+=getCount(root->left,l,h);
          
      }
      if(root->data<h){
       count+=getCount(root->right,l,h);
      }
      if(root->data>=l && root->data<=h){
          count++;
      }
      return count;
    }
};