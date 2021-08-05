class Solution {
public:
    void dfs(vector<vector<int>>&g,int src,vector<bool>&vis){
        vis[src]=true;
        for(auto&i:g[src]){
            if(!vis[i]){
                dfs(g,i,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
        dfs(rooms,0,vis);
        for(int i=0;i<rooms.size();++i){
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
