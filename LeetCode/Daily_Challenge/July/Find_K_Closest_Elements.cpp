class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int>v;
        priority_queue<pair<int,int>>p;
        for(int i=0;i<a.size();++i)
        {
            p.push({abs(a[i]-x),i});
            if(p.size()>k)
                p.pop();
        }
        while(!p.empty())
        {
            v.push_back(a[p.top().second]);
            p.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};
