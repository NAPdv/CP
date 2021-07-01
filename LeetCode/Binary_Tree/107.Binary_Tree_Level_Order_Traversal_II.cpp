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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL) return v;
        stack<vector<int>>s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a;
            int c=q.size();
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            s.push(a);
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

//Simple Without Using Stack , just reverse the 2D Vector ...easy pesy

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a;
            int c=q.size();
            for(int i=0;i<c;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            v.push_back(a);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
