class Solution {
    private:
    
    void dfs(int n,vector<int> adj[],int vis[],vector<int>& arr){
        vis[n]=1;
        arr.push_back(n);
        for(auto i:adj[n]){
            if(!vis[i]){
                dfs(i,adj,vis,arr);
            }
        }
        
    }
   public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> arr;
        int vis[V]={0};
        dfs(0,adj,vis,arr);
        return arr;
    }
};