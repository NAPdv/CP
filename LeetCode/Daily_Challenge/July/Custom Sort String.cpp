class Solution {
public:
    string customSortString(string order, string str) {
        vector<int>h(26,0);
        string res="";

        for(int i=0;i<str.size();++i)
            h[str[i]-'a']++;
        for(int i=0;i<order.size();++i)
        {    while(h[order[i]-'a'])
            {
                res+=order[i];
                h[order[i]-'a']--;
            }
        }
        for(int i=0;i<26;++i)
        {
            while(h[i])
            {
                res+= i +'a';
                h[i]--;
            }
        }
        return res;
    }
};
