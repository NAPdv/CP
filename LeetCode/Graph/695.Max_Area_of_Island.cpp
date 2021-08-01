class Solution {
public:
    int ans=0;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isSafe(vector<vector<int>>&g,int i,int j){
        if(i>=g.size()||j>=g[0].size()||j<0||i<0||g[i][j]==0){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>&g,int i,int j){
        if(!isSafe(g,i,j)){
            return;
        }
        g[i][j]=0;
        ans++;
        for(int k=0;k<4;++k){
            dfs(g,i+dx[k],j+dy[k]);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int res=0;
        for(int i=0;i<g.size();++i){
            for(int j=0;j<g[0].size();++j){
                ans=0;
                if(g[i][j]){
                    dfs(g,i,j);
                    res=max(res,ans);
                }
            }
        }
        return res;
    }
};
