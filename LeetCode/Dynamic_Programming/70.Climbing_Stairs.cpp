class Solution {
public:
    int dp[102];
    int rec(int n)
    {
        if(n<2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = rec(n-1)+rec(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
    
};
