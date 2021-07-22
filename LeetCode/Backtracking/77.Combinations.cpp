class Solution {
public:
    vector<vector<int>>ans;
    void fun(int n,int k,int i,vector<int>&temp)
    {
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k||i==n+1){
            return;
        }
        temp.push_back(i);
        fun(n,k,i+1,temp);
        temp.pop_back();
        fun(n,k,i+1,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        int p=1;
        fun(n,k,p,temp);
        return ans;
    }
};
