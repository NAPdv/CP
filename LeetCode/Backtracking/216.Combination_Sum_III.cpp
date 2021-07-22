class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&temp,int i,int k,int s)
    {
        if(temp.size()==k&&s==0){
            ans.push_back(temp);
            return;
        }
        if(i==10||s<0||temp.size()>k) return;
        temp.push_back(i);
        fun(temp,i+1,k,s-i);
        temp.pop_back();
        fun(temp,i+1,k,s);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        fun(temp,1,k,n);
        return ans;
    }
};
