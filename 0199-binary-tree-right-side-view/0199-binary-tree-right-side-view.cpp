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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            vector<int>temp;
            int x = q.size();
            for(int i = 0;i<x;i++)
            {
                TreeNode *t = q.front();
                q.pop();
                if(t==NULL)continue;
                temp.push_back(t->val);
                q.push(t->left);
                q.push(t->right);
            }
            if(temp.size())ans.push_back(temp.back());
        }
        return ans;
    }
};