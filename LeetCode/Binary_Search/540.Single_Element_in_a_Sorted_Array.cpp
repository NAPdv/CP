//O(logn) 
//Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if((m==nums.size()-1||nums[m]!=nums[m+1])&&(m==0||nums[m]!=nums[m-1]))
                return nums[m];
            if(m%2==0)
            {
                if(nums[m]==nums[m+1])
                    l=m+1;
                else
                    r=m-1;
            }
            else
            {
                if(nums[m]==nums[m-1])
                    l=m+1;
                else
                    r=m-1;
            }
        }
        return 0;
    }
};


//O(n)
//XOR Technique
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();++i)
        {
            x^=nums[i];
        }
        return x;
    }
};
