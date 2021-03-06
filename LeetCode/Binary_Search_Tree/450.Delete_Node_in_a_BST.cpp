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
    TreeNode * insuc(TreeNode* root)
    {
        TreeNode * c = root;
        c=c->right;
        while(c&&c->left!=NULL)
        {
            c=c->left;
        }
        return c;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val > key) root->left=deleteNode(root->left,key);
        else if(root->val < key) root->right=deleteNode(root->right,key);
        else
        {
            if(root->left == NULL)
            {
                TreeNode * temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL)
            {
                TreeNode * temp = root->left;
                delete root;
                return temp;
            }
            
            TreeNode * temp = insuc(root);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);

        }
        return root;
    }
};
