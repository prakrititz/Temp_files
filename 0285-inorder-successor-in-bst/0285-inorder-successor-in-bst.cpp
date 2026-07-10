/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode*prev = NULL;
    TreeNode*curr = root;
    while(curr!=p)
    {
        if(curr->val<p->val)
        {
            curr = curr->right;
        }
        else{
            prev= curr;
            curr = curr->left;
        }
    }
    if(curr->right ==NULL && prev==NULL)return NULL;
    else if(curr->right==NULL)return prev;
    curr = curr->right;
    while(curr->left!=NULL)
    {       
        curr = curr->left;
    }   
    return curr;
}
};