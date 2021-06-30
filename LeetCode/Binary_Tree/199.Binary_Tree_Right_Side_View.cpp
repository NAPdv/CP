/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int c = q.size();
            for(int i=0;i<c;++i)
            {
                TreeNode* u = q.front();
                q.pop();
                if(i==c-1)
                    v.push_back(u->val);
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
        }
        return v;
    }
};
