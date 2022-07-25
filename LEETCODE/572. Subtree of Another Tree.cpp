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

// LINK TO PROBLEM =  https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
public:
        
    bool areIdentical(TreeNode * root1, TreeNode *root2) 
    { 
        if (root1 == NULL && root2 == NULL) 
            return true; 

        if (root1 == NULL || root2 == NULL) 
            return false; 

        return (root1->val == root2->val && 
                areIdentical(root1->left, root2->left) && 
                areIdentical(root1->right, root2->right) ); 
    } 
        
        
        
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            
            if (areIdentical(root,subRoot)){
            return true;  
            } 
            
            queue<TreeNode*> q;
            q.push(root);
            
            while(!q.empty()){
                int n= q.size();
                vector<int> v;
                for(int i=0;i<n;i++){
                    TreeNode* x = q.front();
                    if(areIdentical(x,subRoot)){
                        return true;
                    }
                    q.pop();
                    if(x->left){
                        q.push(x->left);
                        
                    }
                    
                    if(x->right){
                        q.push(x->right);
                        
                    }
                
                }

                }
                return false;
        }
};