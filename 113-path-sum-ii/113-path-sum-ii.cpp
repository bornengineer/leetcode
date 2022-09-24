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
// the idea is - we will maintain a global 2d vector "ret" and create a temp vector
    // to include all the root->val 's till now and we just check each time - if the
    // targetSum == 0 & root's left & right == null and just push_back "temp" to "ret"
	// else we will continue ahead by calling dfs on left and right subtree
	// "Believe me it works like magic"
    vector<vector<int>> ret;
    
    void dfs(TreeNode* root, int targetSum, vector<int> temp){
        if(!root)return;
        
        targetSum -= root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right && targetSum == 0)ret.push_back(temp);
        
        dfs(root->left, targetSum, temp);
        dfs(root->right, targetSum, temp);
    }
        
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        // each time we'll be calling rec, we send the "temp" vector's copy
        // which is formed till now (if we pass it by ref we will get all the values)
        dfs(root, targetSum, temp);
        return ret;
    }
};