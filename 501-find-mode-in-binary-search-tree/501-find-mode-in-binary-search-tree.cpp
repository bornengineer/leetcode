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
    vector<int> res;
    int max = 0, cnt = 1, prev = INT_MIN;
    
    // using inorder traversal to go to left -> root -> right because it is the increasing order in BST
    void dfs(TreeNode* root){
        if(!root)return;
        
        dfs(root->left);
        
        if(prev != INT_MIN){
            if(prev == root->val)cnt++;
            else cnt = 1;
        }
        
        if(cnt > max){
            max = cnt;
            res.clear();
            res.push_back(root->val);
        }
        else if(cnt == max){
            res.push_back(root->val);
        }
        
        prev = root->val;
        
        dfs(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};