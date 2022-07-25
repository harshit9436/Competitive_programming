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
 //LINK TO PROBLEM https://leetcode.com/problems/find-largest-value-in-each-tree-row/
class Solution {
public:
//BFS
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int n=q.size();
            int a=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                    a=max(a,x->left->val);
                    q.push(x->left);
                }
                if(x->right){
                    a=max(a,x->right->val);
                    q.push(x->right);
                }
                
            }
            ans.push_back(a);
        }
        ans.pop_back();
        return ans;
    }
};