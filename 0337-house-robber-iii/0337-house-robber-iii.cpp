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
    void dfs(TreeNode*curr, map<TreeNode*, int>&dp1, map<TreeNode*, int>&dp2)
    {
        if(!curr)return;
        dfs(curr->left, dp1, dp2);
        dfs(curr->right, dp1, dp2);
        dp1[curr] = max(dp1[curr->left], dp2[curr->left]) + max(dp1[curr->right], dp2[curr->right]);
        dp2[curr] = curr->val + dp1[curr->left] + dp1[curr->right];       
        return; 
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int>dp1;
        map<TreeNode*, int>dp2;
        dp1[NULL] = 0;
        dp2[NULL] = 0;
        dfs(root, dp1, dp2);
        return max(dp1[root], dp2[root]);

    }
};