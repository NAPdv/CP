public:
    int dp_cc(vector<int>&a,int s)
    {
        int n=a.size();
        int dp[n+1][s+1];
        for(int i=0;i<=s;++i)  dp[0][i] = INT_MAX-1;
        for(int i=1;i<=n;++i)  dp[i][0] = 0;
        for(int i=1;i<=s;++i) 
        {
            if(i%a[0] == 0)
                dp[1][i] = i/a[0];
            else
                dp[1][i] = INT_MAX-1;
        }
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=s;++j)
            {
                if(a[i-1]<=j)
                    dp[i][j] = min(1+dp[i][j-a[i-1]] , dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    int coinChange(vector<int>& coins, int amount) {
        int p = dp_cc(coins,amount);
        if(p>=INT_MAX-1)
            return -1;
        else return p;
    }
};
