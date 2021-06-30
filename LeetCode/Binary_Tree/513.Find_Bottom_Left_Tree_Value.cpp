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
    int findBottomLeftValue(TreeNode* root) {
        int a;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int c=q.size();
            for(int i=0;i<c;++i)
            {
                TreeNode* u =q.front();
                q.pop();
                if(i==0)
                    a=u->val;
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            
        }
        return a;
    }
};
