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
    int rec(TreeNode* curr, unordered_map<TreeNode*,int>& dp)
    {
        if(curr==NULL)
            return 0;
        if(dp[curr]!=NULL) 
            return dp[curr];
        int notTake = rec(curr->left, dp) + rec(curr->right, dp);
        int take = curr->val;
        if(curr->left!=NULL)
            take += rec(curr->left->left, dp) + rec(curr->left->right, dp);
        if(curr->right!=NULL) 
            take += rec(curr->right->left, dp) + rec(curr->right->right, dp);
        dp[curr] = max(take, notTake);
        return dp[curr];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return rec(root, dp);
    }
};