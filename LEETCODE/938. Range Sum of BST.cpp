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


//LINK https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    void sum(TreeNode*root,int l,int h)
    {
        if(!root)return;
        int v=root->val;
        
        if(v<=h and v>=l){
            res+=v;
            sum(root->left,l,h);
            sum(root->right,l,h);
        }
        
        if(v<l)sum(root->right,l,h);
        else if(v>h)sum(root->left,l,h);
        
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
    int res=0;
        
        sum(root,low,high);
        return res;
    }
    
    
};