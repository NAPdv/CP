class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int next=(m+1)%nums.size();
            int prev=(m+nums.size()-1)%nums.size();
            if(nums[m]<=nums[prev]&&nums[m]<=nums[next])
            {
                return nums[m];
            }
            else if(nums[m]>=nums[l]&&nums[m]>=nums[r])
            {
                l=m+1;
            }
            else if(nums[m]<=nums[r]&&nums[l]>=nums[m])
            {
                r=m-1;
            }
            else
            {
                r=m-1;
            }
        }
        return -1;
    }
};

//Best One

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]<nums[r])
                r=m;
            else
                l=m+1;
        }
        return nums[l];
    }
};
