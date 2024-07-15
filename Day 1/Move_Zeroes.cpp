class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        
         vector<int>temp;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                temp.push_back(nums[i]);
                c++;
            }
        }
         for(int i=c;i<nums.size();i++)
        {   
            temp.push_back(0);
        }
         for(int i=0;i<temp.size();i++)
        {   
           nums[i]=temp[i];
        }
        
    }
};