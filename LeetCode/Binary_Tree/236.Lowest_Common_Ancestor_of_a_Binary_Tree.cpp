class Solution {
public:
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode *n1 = lowestCommonAncestor(root->right,p,q);
        TreeNode *n2 = lowestCommonAncestor(root->left,p,q);
        if(n1!=NULL&&n2!=NULL)
            return root;
        if(n1!=NULL)
            return n1;
        else
            return n2;
    }
};
