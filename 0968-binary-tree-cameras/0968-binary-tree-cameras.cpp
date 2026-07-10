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
    void dfs(map<TreeNode*, int>&dp1, map<TreeNode*, int>&dp2, map<TreeNode*, int>&dp3, TreeNode*curr)
    {
        if(curr==NULL){
            dp1[curr] = 1e8;
            dp2[curr] = 0;
            dp3[curr] = 0;
            return;
        }
        dfs(dp1, dp2, dp3, curr->left);
        dfs(dp1, dp2, dp3, curr->right);
        dp1[curr] = 1 + min({dp1[curr->right], dp2[curr->right], dp3[curr->right]}) + min({dp1[curr->left], dp2[curr->left], dp3[curr->left]});
        dp2[curr] = dp3[curr->right] + dp3[curr->left];
        dp3[curr] = min({
            dp1[curr->right] + min({dp1[curr->left], dp3[curr->left]}), 
            dp1[curr->left] +  min({dp1[curr->right], dp3[curr->right]}),
            dp1[curr->left] + dp1[curr->right]
        });
    }
    int minCameraCover(TreeNode* root) {
        map<TreeNode*, int>put;
        map<TreeNode*, int>not_put_uncovered;
        map<TreeNode*, int>not_put_covered;
        dfs(put, not_put_uncovered, not_put_covered, root);
        return min(put[root], not_put_covered[root]);
    }
};