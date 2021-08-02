class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool isSafe(vector<vector<char>>&g,int i,int j){
        if(i>=g.size()||j>=g[0].size()||i<0||j<0||g[i][j]=='0') return false;
        return true;
    }
    void fun(vector<vector<char>>&g,int i,int j){
        if(!isSafe(g,i,j)) return ;
        g[i][j]='0';
        for(int k=0;k<4;++k){
            fun(g,i+dx[k],j+dy[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    c++;
                    fun(grid,i,j);
                }
            }
        }
        return c;
    }
};
