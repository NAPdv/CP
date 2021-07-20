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
        unordered_set<int>s;
        for(int j=i;j<nums.size();++j)
        {
            if(s.find(nums[j])==s.end())
            {
                s.insert(nums[j]);
                swap(nums[i],nums[j]);
                fun(nums,i+1);
                swap(nums[i],nums[j]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i=0;
        fun(nums,i);
        return ans;
    }
};
