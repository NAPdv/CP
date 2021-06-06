class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int c=1;
        
        sort(nums.begin(),nums.end());
        int p=nums[0];
        int res=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==p+1)
            {
                
                c++;
                p=nums[i];
                res=max(c,res);
            }
            else if(nums[i]!=p)
            {
                
                p=nums[i];
                c=1;
            }
        }
        return res;
    }
};
