void inorder(Node* root, vector<int>&v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
float findMedian(struct Node *root)
{
      vector<int>v;
      inorder(root,v);
      float ans;
      int n=v.size();
      if(n%2==0){
          ans=(float)(v[n/2]+v[(n/2)-1])/2;
          return ans;
      }
      ans=(float)v[n/2];
      return ans;
}