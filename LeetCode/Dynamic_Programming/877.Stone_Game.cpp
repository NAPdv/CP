class Solution {
public:
    int dp[502][502];
    
    int gt(vector<int>&a,int i,int j)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1==j)
        {
            return dp[i][j] = max(a[i],a[j]);
        }
        return dp[i][j] = max(a[i]+min(gt(a,i+2,j),gt(a,i+1,j-1)),a[j]+min(gt(a,i,j-2),gt(a,i+1,j-1)));
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<piles.size();++i)
        {
            sum+=piles[i];
        }
        int res=gt(piles,0,piles.size()-1);
        return (res>sum-res);
    }
};
