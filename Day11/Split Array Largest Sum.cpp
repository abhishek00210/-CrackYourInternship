class Solution {
public:

    bool check(vector<int>& nums, int k, int target){
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=target) temp+=nums[i];
            else {
                if(nums[i]<=target) temp=nums[i];
                else return false;
                k--;
            }

            if(k<0) return false;
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int l = 0, h = sum;
        int ans = sum;
        while(l<=h){
            int m = (l+h)/2;
            if(check(nums,k-1,m)){
                ans = min(m,ans);
                h=m-1;
            }
            else l=m+1;
        }

        return ans;
    }
};