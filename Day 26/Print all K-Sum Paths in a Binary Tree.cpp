class Solution {
  public:
    void solve(Node * root, int &k, int &ans, vector<int> & arr){
        if(root == NULL){
            return ;
        }
        arr.push_back(root -> data);
        solve(root -> left, k, ans, arr);
        solve(root -> right, k, ans, arr);
        int sum = 0;
        for(int i = arr.size()-1;i>=0;--i){
            sum += arr[i];
            if(sum == k){
                ans++;
            }
        }
        arr.pop_back();
    } 
    int sumK(Node *root, int k) {
        // code here
        vector<int> arr;
        int ans;
        solve(root,k,ans,arr);
        return ans;
    }
};