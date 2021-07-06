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
private:
    int s;
public:
    
    void in(TreeNode*root,int L,int R)
    {
        if(root==NULL) return;
        in(root->left,L,R);
        if(root->val>=L&&root->val<=R)
        {
            s+=root->val;
        }
        in(root->right,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        s=0;
        in(root,L,R);
        return s;
    }
};
