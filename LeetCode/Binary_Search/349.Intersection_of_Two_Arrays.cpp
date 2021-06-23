class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int a[10002]={0};
        for(int i=0;i<nums1.size();++i)
        {
            if(a[nums1[i]]==0)
            a[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();++i)
        {
            if(a[nums2[i]])
            {
                v.push_back(nums2[i]);
                a[nums2[i]]--;
            }
        }
        return v;
    }
};
