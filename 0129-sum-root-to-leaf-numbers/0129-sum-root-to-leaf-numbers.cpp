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
    int total = 0;
    void dfs(TreeNode* root, int curr)
    {
        if(root== NULL){
            return;
        }
        int x  = curr*10+ root->val;
        if(root->left == NULL && root->right== NULL)total += x;
        dfs(root->left, x);
        dfs(root->right, x); 
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return total;
    }
};