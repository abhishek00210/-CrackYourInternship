class Solution {
  public:
    #define ll long long
    ll x[4]={0,1,0,-1};
    ll y[4]={1,0,-1,0};
    vector<string> ans;
    void get(ll i,ll j,ll n,vector<vector<int>> &mat,string currP,vector<vector<bool>>& vis){
        if(i==n-1&&j==n-1){
            ans.push_back(currP);
            return;
        }
        if(j+1<n&&mat[i][j+1]!=0&&!vis[i][j+1]){
            vis[i][j+1]=1;
            get(i,j+1,n,mat,currP+"R",vis);
            vis[i][j+1]=0;
        }
        if(i+1<n&&mat[i+1][j]!=0&&!vis[i+1][j]){
            vis[i+1][j]=1;
            get(i+1,j,n,mat,currP+"D",vis);
            vis[i+1][j]=0;
        }
        if(j-1>=0&&mat[i][j-1]!=0&&!vis[i][j-1]){
            vis[i][j-1]=1;
            get(i,j-1,n,mat,currP+"L",vis);
            vis[i][j-1]=0;
        }
        if(i-1>=0&&mat[i-1][j]!=0&&!vis[i-1][j]){
            vis[i-1][j]=1;
            get(i-1,j,n,mat,currP+"U",vis);
            vis[i-1][j]=0;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        ll n=mat.size();
        string s="";
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        if(mat[0][0]==0) return ans;
        vis[0][0]=1;
        get(0,0,n,mat,s,vis);
        return ans;
    }
};
