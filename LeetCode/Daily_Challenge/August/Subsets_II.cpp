class Solution {
public:
    set<vector<int>>s;
    void fun(vector<int>&nums,int i,vector<int>&temp){
        if(i==nums.size()){
            vector<int>a=temp;
            sort(a.begin(),a.end());
            s.insert(a);
            return ;
        }
        temp.push_back(nums[i]);
        fun(nums,i+1,temp);
        temp.pop_back();
        fun(nums,i+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(nums,0,temp);
        for(auto &i:s){
            ans.push_back(i);
        }
        return ans;
    }
};
