struct node{
    node*left;
    node*right;
    node(){
        left=NULL;
        right=NULL;
    }
};
class trie{
    private:
    node *root;
    public:
    trie(){
        root = new node();
    }
    void insert(int n){
        node *temp = root;
        for(int i=31;i>=0;--i){
            int bit=(n)&(1<<i);
            if(!bit){
                if(temp->left==NULL){
                    temp->left=new node();
                }
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right=new node();
                }
                temp=temp->right;
            }
        }
    }
    int helper(int value){
        int c=0;
        node *temp=root;
        for(int j=31;j>=0;--j){
            int bit=(value)&(1<<j);
            if(!bit){
                if(temp->right){
                    temp=temp->right;
                    c+=(1<<j);
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->left){
                    temp=temp->left;
                    c+=(1<<j);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return c;
    }
    int fun(vector<int>&a,int n){
        int m=0;
        for(int i=0;i<n;++i){
            insert(a[i]);
            int c=helper(a[i]);
            m=max(c,m);
        }
        return m;
    }
    
};
    class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        return t.fun(nums,nums.size());
    }
};
