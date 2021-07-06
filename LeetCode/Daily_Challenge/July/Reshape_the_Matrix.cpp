class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c) return mat;
        vector<int>v;
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
                v.push_back(mat[i][j]);
        }
        vector<vector<int>>res(r,vector<int>(c));
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                res[i][j] = v[i*c+j];
            }
        }
        return res;
    }
};
//Another Approach
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(m*n!=r*c) return mat;
        int x=0,y=0;
        vector<vector<int>>res(r,vector<int>(c,0));
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                res[i][j] = mat[x][y++];
                if(y==m)
                {
                    y=y%m;
                    x++;
                }
            }
        }
        return res;
    }
};
