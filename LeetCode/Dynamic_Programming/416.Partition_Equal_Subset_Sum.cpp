class Solution {
public:
    int dp[202][10002];
    bool mem_rec(vector<int>&a,int s,int n)
    {
        if(dp[n][s]!=-1) return dp[n][s];
        if(s==0) return true;
        if(n==0) return false;
        
        if(a[n-1]<=s)
            return dp[n][s] = mem_rec(a,s-a[n-1],n-1) || mem_rec(a,s,n-1);
        return dp[n][s] = mem_rec(a,s,n-1);
    }
    bool canPartition(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        int s=0;
        for(int i=0;i<a.size();++i)
        {
            s+=a[i];
        }
        if(s&1) return 0;
        return mem_rec(a,s/2,a.size());
    }
};
