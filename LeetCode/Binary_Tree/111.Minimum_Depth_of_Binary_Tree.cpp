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
//DFS Solution
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left && root->right) return min(minDepth(root->left),minDepth(root->right)) + 1;
        return max(minDepth(root->left),minDepth(root->right))+1;
    }
};
//BFS Solution
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        
        q.push(root);
        int l=0;
        while(!q.empty())
        {
            int c=q.size();
            l++;
            for(int i=0;i<c;++i)
            {
                TreeNode* p =q.front();
                q.pop();
                if(!p->left&&!p->right)
                {
                    return l;
                }
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return l;
    }
};
