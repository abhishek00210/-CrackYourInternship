class Solution {
  public:
  
  bool detect(int src,vector<int>adj[], int vist[])
  {
      vist[src]=1;
      
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty())
      {
          int node=q.front().first;
          int parent=q.front().second;
          
          q.pop();
          
          for(auto adjand: adj[node])
          {
              if(!vist[adjand])
              {
                  vist[adjand]=1;
                  q.push({adjand,node});
              }
              else if(parent!=adjand)
              {
                  return true;
              }
          }
      } return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};