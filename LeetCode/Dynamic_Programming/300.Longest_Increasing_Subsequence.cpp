//O(n*n)
//DP - Solution (LIS)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,0);
        lis[0]=1;
        for(int i=1;i<nums.size();++i)
        {
            lis[i]=1;
            for(int j=i-1;j>=0;--j)
            {
                if(nums[i]>nums[j])
                {
                    lis[i] = max(lis[i],1+lis[j]);
                }
            }
        }
        int m=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            m=max(m,lis[i]);
        }
        return m;
    }
};

//O(nlogn)
//Binary Search
class Solution {
public:
    int bs(vector<int>&a,int x)
    {
        int l=0;
        int res=0;
        int r=a.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(a[m]==x)
            {
                return m;
            }
            else if(a[m]>x)
            {
                res=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]>lis[lis.size()-1])
            {
                lis.push_back(nums[i]);
            }
            else 
            {
                int index = bs(lis,nums[i]);
                lis[index] = nums[i];
            }
        }
        return lis.size();
        
    }
};
