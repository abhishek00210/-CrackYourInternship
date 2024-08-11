class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
          vector<vector<int>>ans = image;
        queue<pair<int,int>>q;

        int vist[n][m];
        
        
        q.push({sr,sc});
        int oldcolor=image[sr][sc];
        ans[sr][sc]=color;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldcolor &&
                ans[nrow][ncol]!=color)
                {
                    
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=color;
                    
                }
            }
        }

        return ans;

    }
};