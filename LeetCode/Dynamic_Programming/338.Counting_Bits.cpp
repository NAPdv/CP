//O(n) Solution
//if n%2 == 0 then dp[n] = dp[n/2] ; (as 0 bit is added, only the bits are shifted all together)
//else dp[n] = dp[n/2] + 1 ; (as a bit is added at 0 index, to make it odd after shifting of whole (previous) bits )
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=dp[i/2]+i%2;
        }
        return dp;
    }
};
