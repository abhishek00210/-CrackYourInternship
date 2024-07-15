class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,promax=0,min=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(min>prices[i])
            {
                min=prices[i];
                // profit=prices-min;
                // promax=max(profit,promax);
            }
            
            profit=prices[i]-min;
            promax=max(profit,promax);
        }
        return promax;
    }
};