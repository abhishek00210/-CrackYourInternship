class Solution 
{
    private:
        bool isValid(vector<vector<int>>& grid,int nr,int nc){
            int n=grid.size();
            int m=grid[0].size();
            // if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc]==0 || grid[nr][nc]==2)
            //     return false;
            // return true;
            if(nr>=0 && nc >=0 && nr<n && nc<m && grid[nr][nc]==1)
                return true;
            return false;
        }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int res=0;
        int totalorages=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    totalorages++;
                }
            }
        }
        
        if(totalorages==0)
            return 0;
        if(q.empty())
            return -1;
        
        while(!q.empty()){
            int len=q.size();
            int hasrotton=false;
        //   cout<<len<<endl;
            while(len--){
                pair<int,int>t=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nr=t.first+dx[i];
                    int nc=t.second+dy[i];
                    if(isValid(grid,nr,nc)){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        totalorages--;
                        hasrotton=true;
                    }
                }
                // len--;
            }
            if(hasrotton) res++;
        }
        
        if(totalorages>0)
            return -1;
        return res;
    }
};