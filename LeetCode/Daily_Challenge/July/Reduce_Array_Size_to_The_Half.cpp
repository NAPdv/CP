class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        int n=arr.size();
        for(auto &i:arr)
        {
            m[i]++;
        }
        vector<int>v;
        for(auto &i:m)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int c=0;
        int res=0;
        for(auto &i:v)
        {
            if(res>=n/2) break;
            res+=i;
            c++;
            
        }
        return c;
    }
};
