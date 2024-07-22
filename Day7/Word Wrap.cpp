class Solution {
public:
    vector<vector<int>>dp;
    int solve(int taken,int i, vector<int>& nums,int k){
        if(dp[i][taken]!=-1) return dp[i][taken];
        int n=nums.size();
        int ans;
        if(i==n-1){
            if(k-taken>=nums[i]) ans=0;
            else ans=(k-taken+1)*(k-taken+1);
        }
        else if(taken==0){
            ans=solve(nums[i]+1,i+1,nums,k);
        }
        else if(k-taken>=nums[i]){
            ans=min(solve(nums[i]+1+taken,i+1,nums,k),(k-taken+1)*(k-taken+1)+solve(0,i,nums,k));
        }
        else ans=(k-taken+1)*(k-taken+1)+solve(0,i,nums,k);
        //cout<<"i:"<<i<<" taken:"<<taken<<" ans:"<<ans<<endl;
        dp[i][taken]=ans;
        return ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        dp.resize(n,vector<int>(k+2,-1));
        return solve(0,0,nums,k);
        /*// Code here
        int j=0;
        int n=nums.size();
        int i=1;
        int ans=0;
        int x=k;
        while(true){
            cout<<"x:"<<x<<" j:"<<j<<" ans:"<<ans<<endl;
            if(nums[j]<=x){
                x-=nums[j];
                x--;
                j++;
                if(j==n) break;
            }
            else{
                //++j;
                //if(j==n) break;
                ans+=x+1;
                x=k;
            }
            cout<<"x:"<<x<<" j:"<<j<<" ans:"<<ans<<endl;
        }
        return ans;*/
    } 
};