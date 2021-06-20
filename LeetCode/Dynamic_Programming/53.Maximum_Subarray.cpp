class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=nums[0];
        int p=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            s=max(s+nums[i],nums[i]);
            p=max(s,p);
        }
        return p;
    }
};
