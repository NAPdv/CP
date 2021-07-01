class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int c=q.size();
            vector<int>a;
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                // cout<<temp->val<<endl;
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(f)
            {
                reverse(a.begin(),a.end());
            }
            f=(f+1)%2;
            v.push_back(a);
        }
        return v;
       
    }
};
