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
    int ans = INT_MAX;
    pair<int, int> dfs(TreeNode* curr)
    {
        if(curr==NULL)return {INT_MAX, INT_MIN};
        pair<int, int>l = dfs(curr->left);
        pair<int,int>r = dfs(curr->right);
        int L = INT_MAX;
        int R = INT_MAX;
        if(l.second != INT_MIN)L = abs(curr->val - l.second);
        if(r.first != INT_MAX)R = abs(curr->val - r.first);
        ans  =  min(ans, min(L, R));
        int mx = curr->val;
        int mn = curr->val;
        if (l.first != INT_MAX)
            mn = l.first;
        if (r.second != INT_MIN)
            mx = r.second;
        return {mn, mx};
    }
    int getMinimumDifference(TreeNode* root) {
        pair<int, int>d = dfs(root);
        return ans;     
    }
};