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

 //LINK TO PROBLEM https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
//BFS with modifications
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        ans.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int n= q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                    q.push(x->left);
                    v.push_back(x->left->val);
                }
                
                if(x->right){
                    q.push(x->right);
                    v.push_back(x->right->val);
                }
            
            }
            if(flag==0){
                reverse(v.begin(), v.end());
            }
            flag = flag^1;
            ans.push_back(v);
        }
        ans.pop_back();
        return ans;
    }
};

