
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
 //link https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
    vector<vector<int>> ans;
    queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front() ;
                q.pop();
                v.push_back(x->val);
                if(x->left !=NULL) q.push(x->left);
                if(x->right !=NULL) q.push(x->right);
            }
            
            ans.push_back(v);
            v={};
        }
        return ans;
       
    }
};