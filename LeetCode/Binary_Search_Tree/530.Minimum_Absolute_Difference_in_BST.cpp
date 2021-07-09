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
    int res=INT_MAX;
    int p=-1;
    void ino(TreeNode * root)
    {
        if(root)
        {
            ino(root->left);
            if(p!=-1)
            {
              res=min(res,abs(root->val-p));  
            }
            p=root->val;
            ino(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        ino(root);
        return res;
    }
};
