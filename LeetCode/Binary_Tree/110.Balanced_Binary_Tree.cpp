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
    int height(TreeNode * root)
    {
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(!isBalanced(root->left) ||!isBalanced(root->right))
        {
            return false;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return (abs(lh-rh)<=1);
    }
};
class Solution {
public:
    int height = 0;
    bool isB(TreeNode * root, int *height)
    {
        if(!root) return true;
        int lh=0,rh=0;
        if(!isB(root->left,&lh) || !isB(root->right,&rh)) return false;
        *height = max(lh,rh) + 1;
        if(abs(lh-rh)<=1) return true;
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        return isB(root,&height);
    }
};
