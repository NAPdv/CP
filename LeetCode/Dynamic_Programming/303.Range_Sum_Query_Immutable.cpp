class NumArray {
    vector<int>v;
public:
    
    NumArray(vector<int>& nums) {
        v.push_back(nums[0]);
        int s=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            s+=nums[i];
            v.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return v[right];
        return v[right] - v[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
