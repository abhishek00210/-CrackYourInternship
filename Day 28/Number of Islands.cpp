class Solution {
private:
    // up, right, down, left
    vector<pair<int,int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    set<pair<int,int>> visited;

    void bfs(int i, int j, vector<vector<char>>& grid) {

        queue<pair<int,int>> q;
        visited.insert({i,j});
        q.push({i,j});
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();

            for (auto d : dirs) {
                int x = cur.first + d.first;
                int y = cur.second + d.second;
                
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;

                if (grid[x][y] == '1' && !visited.contains({x,y})) {
                    q.push({x,y});
                    visited.insert({x,y});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        // run bfs from each starting point
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1' && !visited.contains({i,j})) {
                    bfs(i, j, grid);
                    res++;
                }
            }
        }

        return res;
    }
};