class Solution {
public:
    int ub(vector<int>&a,int x)
    {
        int l=0;
        int r=a.size()-1;
        int res = 0;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(a[m]==x)
                return m;
            else if(a[m]<x)
            {
                l=m+1;
            }
            else
            {
                res=m;
                r=m-1;
            }
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            if(lis[lis.size()-1]<nums[i])
                lis.push_back(nums[i]);
            else
            {
                int idx = ub(lis,nums[i]);
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }
};
