class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&a,int s,vector<int>&temp,int i)
    {
        
        if(s==0){
            ans.push_back(temp);
            return ;
        }
        if(i==a.size()||s<0){
            return;
        }
        temp.push_back(a[i]);
        fun(a,s-a[i],temp,i);
        temp.pop_back();
        fun(a,s,temp,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        int k=0;
        fun(candidates,target,temp,k);
        return ans;
    }
};
