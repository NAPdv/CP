class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool check(vector<vector<int>>&g,int i,int j){
        if(i>=g.size()||j>=g[0].size()||i<0||j<0||g[i][j]!=1)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int c=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;\
                    
                }
                if(grid[i][j]==1){c++;}
            }
        }
        int res=0;
        while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int x=temp.first+dx[i];
                int y=temp.second+dy[i];
                if(check(grid,x,y)){
                    q.push({x,y});
                    grid[x][y]=grid[temp.first][temp.second]-1;
                    res=min(res,grid[x][y]);
                    c--;
                }
            }
        }      
        if(c) return -1;
        return abs(res);
    }
};
