class Solution {
public:
	bool isPossible(int n,int m,vector<pair<int,int>> &v) {
	    vector<vector<int>> adj(n);
	    vector<int> indegree(n,0);
	    for(int i=0;i<m;i++){
	        adj[v[i].first].push_back(v[i].second);
	        indegree[v[i].second]++;
	    }
	    int cnt=0;
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int i=q.front();
	        q.pop();cnt++;
	        for(auto x:adj[i]){
	            indegree[x]--;
	            if(indegree[x]==0) q.push(x);
	        }
	    }
	    return cnt==n;
	}
};