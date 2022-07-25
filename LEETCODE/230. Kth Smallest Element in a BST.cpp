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
//LINK TO PROBLEM https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
// iterative inorder traversal  
int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> stk;
        stk.push(root);
        int n=0;
        while( !stk.empty()){
            while(root!=NULL){
                stk.push(root);
                root = root->left;
            }
             root = stk.top();
            stk.pop();
            n+=1 ;
            if(n==k){
                return root->val;
            }
            root = root->right;
            
        }
        return 0;
        
        
}
    
   
};