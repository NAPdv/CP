//BFS Solution
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode * >q;
        q.push(root);
        int c=root->val;
        while(!q.empty())
        {
            TreeNode * p = q.front();
            if(p->val!=c) return false;
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);            
        }
        return true;
    }
};
//DFS Solution
class Solution {
public:
    set<int>s;
    void tr(TreeNode* root)
    {
        if(root==NULL) return ;
        s.insert(root->val);
        tr(root->left);
        tr(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        tr(root);
        return (s.size() == 1);
    }
};
