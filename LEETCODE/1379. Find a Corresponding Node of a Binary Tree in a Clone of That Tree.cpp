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
//BFS
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       queue<TreeNode*> q;
        queue<TreeNode*> c;
        q.push(original);
        c.push(cloned);
        while(!q.empty()){
            TreeNode* temp = q.front();
            TreeNode* temp2 = c.front();
            q.pop();
            c.pop();
            if(temp==target){
                return temp2;
            }
            if(temp->left!=NULL) {
                q.push(temp->left);
                c.push(temp2->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                c.push(temp2->right);
            }
            
        }
        return original;
    }
};