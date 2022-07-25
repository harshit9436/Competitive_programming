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
 //LINK https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    
    bool solve(TreeNode* root, long long int left, long long int right){
        if(root == NULL ) return true;
        if(!(root->val > left && root->val <right)) return false;
        
        return solve(root->left, left, root->val) 
                && solve(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN,LONG_MAX);
    }
};