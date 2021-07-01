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
    vector<double> averageOfLevels(TreeNode* root) {
        double d;
        vector<double>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int c=q.size();
            d=0;
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                d+=(double)(temp->val);
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
            d=(d*1.0)/(c*1.0);
            v.push_back(d);
        }
        return v;
    }
};
