class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&graph,vector<bool>&vis,int src,vector<int>&temp)
    {
        vis[src]=true;
        temp.push_back(src);
        if(src==graph.size()-1){
            ans.push_back(temp);
        }
        for(auto &ng:graph[src])
        {
            if(!vis[ng])
            {
                dfs(graph,vis,ng,temp);
            }
        }
        temp.pop_back();
        vis[src]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<bool>vis(v,false);
        vector<int>temp;
        int src=0;
        dfs(graph,vis,src,temp);
        return ans;
    }
};
