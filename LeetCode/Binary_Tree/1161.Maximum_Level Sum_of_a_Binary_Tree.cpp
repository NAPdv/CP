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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=INT_MIN;
        int l=0;
        int p=0;
        int s=0;
        while(!q.empty())
        {
            int c=q.size();
            s=0;
            l++;
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                s+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            // cout<<s<<endl;
            if(s>res)
            {
                res=s;
                p=l;
            }
        }
        return p;
    }
};
