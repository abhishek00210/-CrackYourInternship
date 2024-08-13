class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=true;

        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node].at(i)]) dfs(adj,visited,adj[node].at(i));
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        int ans=0;

        for(int i=0;i<connections.size();i++){
            int u=connections[i].at(0);
            int v=connections[i].at(1);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
        }

        if(connections.size()<(n-1)) return -1;

        return ans-1;
    }
};