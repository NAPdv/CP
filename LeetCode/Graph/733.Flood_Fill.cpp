class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    bool check_ff(vector<vector<int>>&g,int i,int j,int c,vector<vector<bool>>&vis){
        if(i>=g.size()||j>=g[0].size()||i<0||j<0||g[i][j]!=c||vis[i][j]){
            return false;
        }
        return true;
    }
    void flood_fill(vector<vector<int>>&image,int si,int sj,int color,int c,vector<vector<bool>>&vis){
        if(!check_ff(image,si,sj,c,vis)){
            return;
        }
        vis[si][sj]=true;
        image[si][sj]=color;
        for(int i=0;i<4;++i){
            flood_fill(image,si+dx[i],sj+dy[i],color,c,vis);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size(),0));
        flood_fill(image,sr,sc,newColor,image[sr][sc],vis);
        return image;
    }
};
