class Solution {
public:
    vector<int>v;
    void in(TreeNode*root)
    {
        if(!root) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        in(root);
        TreeNode * curr = new TreeNode(v[0]);
        TreeNode * it = curr;
        for(int i=1;i<v.size();++i)
        {
            it->right = new TreeNode(v[i]);
            it=it->right;
        }
        it->right=NULL;
        return curr;
    }
};

//Better Approach
class Solution {
public:
    void in(TreeNode*root,TreeNode *&ans)
    {
        if(!root) return;
        in(root->left,ans);
        ans->right = new TreeNode(root->val);
        ans=ans->right;
        in(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * ans = new TreeNode();
        TreeNode * temp = ans;
        in(root,ans);
        return temp->right;
    }
};
