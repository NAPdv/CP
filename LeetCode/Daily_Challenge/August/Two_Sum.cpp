class Solution {
public:
    vector<int> twoSum(vector<int>&a, int k) {
        vector<int>v;
        unordered_map<int,int>m;
        m[a[0]]=0;
        for(int i=1;i<a.size();++i){
            if(m.find(k-a[i])!=m.end()){
                v.push_back(m[k-a[i]]);
                v.push_back(i);
                return v;
            }
            m[a[i]]=i;
        }
        return v;
    }
};
