class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int m=prices[0];
        int q=INT_MIN;
        for(int i=0;i<prices.size();++i)
        {
            if(m>prices[i]) m=prices[i];
            q=max(q,prices[i]-m);
        }
        return q;        
    }
};
