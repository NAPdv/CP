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
//BFS Solution
class Solution {
public:

    int deepestLeavesSum(TreeNode* root) {
        int l=1;
        int s=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int c=q.size();
            s=0;
            for(int i=0;i<c;++i)
            {
                TreeNode * p = q.front();
                q.pop();
                s+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            l++;
        }
        return s;
    }
};

//DFS Solution
class Solution {
public:
    int deepest=0,sum=0;
    int deepestLeavesSum(TreeNode* root,int d=0) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
        {
            if(d==deepest) sum+=root->val;
            if(d>deepest) deepest=d,sum=root->val;
        }
        deepestLeavesSum(root->left,d+1);
        deepestLeavesSum(root->right,d+1);
        return sum;
    }
};
