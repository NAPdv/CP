class Solution {
public:
    int dpp[302][5005];
    int cc(vector<int>&c,int k)
    {
        int n = c.size();
        int dp[n+1][k+1];
        for(int i=0;i<=k;++i) dp[0][i] = 0;
        for(int i=0;i<=n;++i) dp[i][0] = 1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=k;++j)
            {
                dp[i][j] = dp[i-1][j];
                if(c[i-1]<=j)
                    dp[i][j] += dp[i][j-c[i-1]];
            }
        }
        return dp[n][k];
    }
    int mem_cc(vector<int>&c,int k,int n)
    {
        if(dpp[n][k]!=-1) return dpp[n][k];
        if(k==0) return dpp[n][k] = 1;
        if(n==0) return dpp[n][k] = 0;
        if(c[n-1]<=k) return dpp[n][k] = mem_cc(c,k-c[n-1],n) + mem_cc(c,k,n-1);
        return dpp[n][k] = mem_cc(c,k,n-1);
    }
    int change(int amount, vector<int>& coins) {
        // return cc(coins,amount);
        memset(dpp,-1,sizeof(dpp));
        return mem_cc(coins,amount,coins.size());
    }
};
