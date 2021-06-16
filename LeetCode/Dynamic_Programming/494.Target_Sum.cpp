class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(int i=0;i<nums.size();++i)
        {
            s+=nums[i];
        }
        target = abs(target);
        if((target+s)%2!=0 || target>s) return 0;
        int d = (target+s)/2;
        int n=nums.size();
        int dp[n+1][d+1];
        for(int i=0;i<=n;++i) dp[i][0] = 1;
        for(int i=1;i<=d;++i) dp[0][i] = 0;
        for(int i=1;i<=n;++i)
        {
            //yanha j=0 se start hoga kyun ki sum 0 bhi calculate krna hai! (cool)
            for(int j=0;j<=d;++j)
            {
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][d];
    }
};
