//Graph
class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<bool>&vis,int src){
        vis[src]=true;
        for(auto&i:g[src]){
            if(!vis[i]){
                dfs(g,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>&v) {
        int n=v.size();
        vector<vector<int>>g(n);
        vector<bool>vis(n,false);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(v[i][j]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                c++;
                dfs(g,vis,i);
            }
        }
        return c;
    }
};
//DSU
class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<bool>&vis,int src){
        vis[src]=true;
        for(auto&i:g[src]){
            if(!vis[i]){
                dfs(g,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>&v) {
        int n=v.size();
        vector<vector<int>>g(n);
        vector<bool>vis(n,false);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(v[i][j]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                c++;
                dfs(g,vis,i);
            }
        }
        return c;
    }
};
