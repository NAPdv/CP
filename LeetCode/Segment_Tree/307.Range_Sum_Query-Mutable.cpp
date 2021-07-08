
class NumArray {
private:
    
    vector<int>tree;
    vector<int>a;
public:
    void build(vector<int>&a,vector<int>&tree,int s,int e,int tidx)
    {
        if(s==e)
        {
            tree[tidx] = a[s];
            return;
        }
        int m = (s+e) / 2;
        build(a,tree,s,m,2*tidx);
        build(a,tree,m+1,e,2*tidx+1);
        tree[tidx] = tree[2*tidx] + tree[2*tidx+1];
    }
    NumArray(vector<int>& nums) {
        a=nums;
        tree.resize(4*a.size());
        build(a,tree,0,a.size()-1,1);
    }
    void up(vector<int>&a,vector<int>&tree,int s,int e,int tidx,int idx,int val)
    {
        if(s==e)
        {
            a[idx] = val;
            tree[tidx] = val;
            return;
        }
        int m=(s+e)/2;
        if(idx>m)
        {
            up(a,tree,m+1,e,2*tidx+1,idx,val);
        }
        else
        {
            up(a,tree,s,m,2*tidx,idx,val);
        }
        tree[tidx] = tree[2*tidx] + tree[2*tidx+1];
    }
    void update(int index, int val) {
        up(a,tree,0,a.size()-1,1,index,val);
    }
    int sr(vector<int>&tree,int s,int e,int tidx,int l,int r)
    {
        if(l>e||r<s)
        {
            return 0;
        }
        if(s>=l&&e<=r)
        {
            return tree[tidx];
        }
        int m = (s+e) / 2;
        int a1 = sr(tree,s,m,2*tidx,l,r);
        int a2 = sr(tree,m+1,e,2*tidx+1,l,r);
        return a1+a2;
    }
    int sumRange(int left, int right) {
        return (sr(tree,0,a.size()-1,1,left,right));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
