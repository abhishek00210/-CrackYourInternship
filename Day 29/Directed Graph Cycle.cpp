class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<int> adj[], vector<bool> & visited, vector<bool>& dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, dfsVisited)) return true;
            }
            else if(dfsVisited[it]){
                return true;
            }
        }
        dfsVisited[node] = false; 
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, dfsVisited)) return true;
            }
        }
        
        return false;
    }
};