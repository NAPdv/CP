//BFS Solution 
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

    int sumOfLeftLeaves(TreeNode* root) {
        int s=0;
        if(root->left==NULL && root->right==NULL) return s;
        queue<pair<TreeNode*,char>>q;
        q.push({root,'R'});
        while(!q.empty())
        {
            int c=q.size();
            for(int i=0;i<c;++i)
            {
                pair<TreeNode*,char> p  = q.front();
                q.pop();
                if(p.first->right==NULL&&p.first->left==NULL&&p.second=='L')
                {
                    s+=p.first->val;
                }
                if(p.first->left) q.push({p.first->left,'L'});
                if(p.first->right) q.push({p.first->right,'R'});
            }
        }
        return s;
    }
};
//DFS Solution
class Solution {
public:
    int sum=0; 
    void solve(TreeNode* root,bool lSide){
        if(!root) return;
        if(!root->left && !root->right && lSide){ 
            sum+=root->val;
        }
        solve(root->left,true);
        solve(root->right,false);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,false);
        return sum;
    }
};
