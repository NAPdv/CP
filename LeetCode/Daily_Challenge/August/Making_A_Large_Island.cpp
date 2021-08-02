class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool check(vector<vector<int>>&grid,int i,int j){
        if(i>=grid.size()|j>=grid[0].size()||i<0||j<0||grid[i][j]!=1){
            return false;
        }
        return true;
    }
    int fun(vector<vector<int>>&grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0){
            return 0;
        }
        else if(grid[i][j]>=2){
            return grid[i][j];
        }
        return 0;
    }
    void dfs(vector<vector<int>>&grid,unordered_map<int,int>&ump,int i,int j,int c){
        if(!check(grid,i,j)){
            return;
        }
        grid[i][j]=c;
        ump[c]++;
        for(int k=0;k<4;++k){
            dfs(grid,ump,i+dx[k],j+dy[k],c);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int c=2;
        unordered_map<int,int>ump;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    dfs(grid,ump,i,j,c);
                    c++;
                }
            }
        }
        int res=0;
        for(auto &i:ump){
            res=max(i.second,res);
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                unordered_set<int>temp;
                if(grid[i][j]==0){
                    for(int k=0;k<4;++k){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        int p=fun(grid,x,y);
                        temp.insert(p);
                    }
                    int ans=0;
                    for(auto &i:temp){
                        if(ump.find(i)!=ump.end()){
                            ans+=ump[i];
                        }
                    }
                    res=max(res,ans+1);
                }
            }
        }
        return res;
    }
};
