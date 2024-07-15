class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       int frq [n + 1] = {
    0
  };

        for(int i=0;i<n;i++)
        {
            if(frq[nums[i]]==0)
            {
                frq[nums[i]]+=1;
            }
            else
            {
                return nums[i];
            }
        }
        
    }
};