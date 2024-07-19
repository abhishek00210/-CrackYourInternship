class Solution {
public:
    
vector<int> nextelement(vector<int> &arr, int n)
{
     stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int cur=arr[i];
            while(s.top() !=-1 && arr[s.top()]>=cur)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        
        return ans;
}
    vector<int> prvelement(vector<int> &arr, int n)
{
     
     stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int cur=arr[i];
            while(s.top() !=-1 && arr[s.top()]>=cur)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        
        return ans;

}
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>next(n);
        next=nextelement(heights,n);

        vector<int>prv(n);
        prv=prvelement(heights,n);

        int maxarea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prv[i]-1;
            
            int area=l*b;
            maxarea=max(area,maxarea);
        }
        return maxarea;
        
    }
};