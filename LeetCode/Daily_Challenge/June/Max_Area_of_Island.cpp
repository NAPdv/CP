class Solution {
public:
    int n,m;
    int vis[51][51];
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int h[3000]={0};
    void dfs(int x, int y , vector<vector<int>>&v , int col)
    {
        vis[x][y]=col;
        
        for(int i=0;i<4;++i)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx>=0&&ty>=0&&tx<n&&ty<m&&!vis[tx][ty]&&v[tx][ty])
            {
                dfs(tx,ty,v,col);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<51;++i)
        for(int j=0;j<51;++j)
            vis[i][j]=0;
        n=grid.size();
        m=grid[0].size();
        
        int col=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!vis[i][j]&&grid[i][j])
                {
                    dfs(i,j,grid,col);
                    col++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                h[vis[i][j]]++;
        }
        for(int i=1;i<col;++i)
        {
            ans=max(ans,h[i]);
        }
        return ans;
    }
};
