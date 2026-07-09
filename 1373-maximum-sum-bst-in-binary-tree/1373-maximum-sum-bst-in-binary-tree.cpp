class Solution {
public:
    int ans = 0;

    vector<int> dfs(TreeNode* root) {
        if (!root)
            return {1, INT_MAX, INT_MIN, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if (l[0] && r[0] &&
            l[2] < root->val &&
            root->val < r[1]) {

            int sum = l[3] + r[3] + root->val;
            ans = max(ans, sum);

            return {
                1,
                min(root->val, l[1]),
                max(root->val, r[2]),
                sum
            };
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};