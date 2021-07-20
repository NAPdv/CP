class Solution {
public:
    set<vector<int>>s;
    void fun(vector<int>&nums,vector<int>&temp,int i)
    {
        if(i==nums.size())
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        fun(nums,temp,i+1);
        temp.pop_back();
        fun(nums,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        int i=0;
        fun(nums,temp,i);
        set<vector<int>>t;
        for(auto &i:s)
        {
            vector<int>p=i;
            sort(p.begin(),p.end());
            t.insert(p);
        }
        for(auto &i:t)
            v.push_back(i);
        return v;
    }
};
