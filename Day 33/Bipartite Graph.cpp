class Solution {
public:
bool bfs(int s, vector<int> adj[], vector<int>& vis){
    vis[s]=0;
    queue<int> st;
    st.push(s);
    while(st.size()>0){
        int t=st.front();
        st.pop();
        for(auto ele:adj[t]){
            if(vis[ele]==-1){
                vis[ele]=!vis[t];
                st.push(ele);
            }
           else if(vis[ele]==vis[t]){
                return false;
            }
        }
    }
    
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	           if( bfs(i,adj,vis)==false){
	               return false;
	           }
	        }
	    }
	    return true;
	    // Code here
	}

};