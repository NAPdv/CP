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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int c=q.size();
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = (q.front()).first;
                int cs = (q.front()).second;
                q.pop();
                if(!temp->left&&!temp->right&&cs+temp->val == targetSum)
                {
                    return true;
                }
                if(temp->left) q.push({temp->left,cs+temp->val});
                if(temp->right) q.push({temp->right,cs+temp->val});
            }
        }
        return false;
        
    }
};
//DFS Solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;                                         
        sum=sum-root->val;                                            
        if(sum==0&&!root->left&&!root->right)return true;             
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    }
};
