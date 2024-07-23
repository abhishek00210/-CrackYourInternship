class Solution{
  public:
  
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
      
        if(nums.size() == 1) return {1};
        vector<long long int> left(n, 1);
        vector<long long int> right(n, 1);

        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            left[i] = left[i-1]*nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1]*nums[i];
        }

        vector<long long int> ans(n, 1);
        ans[0] = right[1];
        ans[n-1] = left[n-2];
        for(int i = 1; i < n-1; i++){
            ans[i] = left[i-1]*right[i+1];
        }

        return ans;
    }
};