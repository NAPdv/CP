class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&nums,int i)
    {
        if(i==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();++j)
        {
            swap(nums[i],nums[j]);
            fun(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        fun(nums,i);
        return ans;
        
    }
};
