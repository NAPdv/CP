int dp[101][101];
int n,m,o;
string s,t,p;
class Solution {
public:
    int lcs(int i,int j,int k)
    {
        if(i==n&&j==m)
        {
            return (o==k);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(i<n)
        {
            if(s[i]==p[k])
            {
                ans|=lcs(i+1,j,k+1);
            }
        }
        if(j<m)
        {
            if(t[j]==p[k])
            {
                ans|=lcs(i,j+1,k+1);
            }
            
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size(),m=s2.size(),o=s3.size();
        s=s1;
        t=s2;
        p=s3;
        memset(dp,-1,sizeof(dp));
        //always => -1,0,1
        return lcs(0,0,0);
    }
};
