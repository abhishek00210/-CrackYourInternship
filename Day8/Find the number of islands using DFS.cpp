 void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m){
        int dir_x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dir_y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int i = 0; i < 8; i++){
            int cur_x = dir_x[i] + row;
            int cur_y = dir_y[i] + col;
            if(cur_x >= 0 && cur_x < n && cur_y >=0 && cur_y < m &&
            grid[cur_x][cur_y] == '1' && vis[cur_x][cur_y] == 0){
                vis[cur_x][cur_y] = 1;
                dfs(grid, vis, cur_x, cur_y, n, m);
            }
        }
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    dfs(grid, vis, i, j, n, m);
                    count++;
                }
                    
            }
        }
        return count;
    }