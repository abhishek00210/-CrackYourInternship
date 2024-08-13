class Solution
{
	public:
    void dfs(int i,stack<int>&st,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;
        
        for(auto it:adj[i]){
            if(!vis[it]) dfs(it,st,adj,vis);
        }
        st.push(i);
    }
    
    void dfs2(int i,vector<int>adj1[],vector<int>&vis,vector<int>&vec){
        vis[i]=1;
        vec.push_back(i);
        
        for(auto it:adj1[i]){
            if(!vis[it]){
                dfs2(it,adj1,vis,vec);
            } 
        }
    }
    
    int kosaraju(int V, vector<vector<int>>&adj)
    {
        stack<int>st;
        vector<int>vis(V,0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, st, adj, vis); //sort according to finishing time
        }
        
        //reverse graph
        vector<int>adj1[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]) adj1[it].push_back(i);
        }
        
        //do dfs traversal
        int scc=0;
        //store each scc(Extra part if in question it is asked that return the all scc)
        vector<vector<int>>ans;
       
        fill(vis.begin(),vis.end(),0);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                vector<int>vec;
                dfs2(node,adj1,vis,vec);
                ans.push_back(vec);
            }
        }
        return scc;
    }
};