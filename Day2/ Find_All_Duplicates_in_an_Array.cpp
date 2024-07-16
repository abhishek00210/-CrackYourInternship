class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1);
        freq={0};
       
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==0)
            {
                freq[nums[i]]+=1;
            }
            else
            {
                ans.push_back(nums[i]);

            }
        }
        return ans;
        
    }
};