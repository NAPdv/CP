class Solution {
public:
    int triangleNumber(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        int c=0;
        for(int k=2;k<nums.size();++k)
        {
            int i=0;
            int j=k-1;
            while(i<j)
            {
                if(nums[k]<nums[i]+nums[j])
                {
                    c+=j-i;
                    j--;
                }
                else
                   i++;
            }
        }
        return c;
    }
};
