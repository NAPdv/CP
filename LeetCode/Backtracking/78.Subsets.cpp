//Backtracking
class Solution {
public:
    void fun(vector<int>&nums,vector<int>&temp,vector<vector<int>>&v,int i)
    {
        if(i==nums.size())
        {
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        fun(nums,temp,v,i+1);
        temp.pop_back();
        fun(nums,temp,v,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        int i=0;
        fun(nums,temp,v,i);
        return v;
    }
};
//Iterative
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int m=1<<n;
        vector<vector<int>>v;
        vector<int>temp;
        for(int i=0;i<m;++i)
        {
            vector<int>temp;
            for(int j=0;j<n;++j)
            {
                if((i&(1<<j))){
                    temp.push_back(nums[j]);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};
