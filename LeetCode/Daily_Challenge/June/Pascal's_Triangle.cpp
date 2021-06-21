class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        
        for(int i=1;i<=numRows;++i)
        {
            vector<int>a;
            int c=1;
            for(int j=1;j<=i;++j)
            {
                a.push_back(c);
                c=c*(i-j)/j;
            }
            v.push_back(a);
        }
        return v;
    }
};
