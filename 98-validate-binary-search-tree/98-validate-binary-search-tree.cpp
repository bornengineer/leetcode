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
    void findLMax(TreeNode* root, long* leftMax){
        if(!root)return;
        *leftMax = max(*leftMax,(long)root->val);
        
        findLMax(root->left, leftMax);
        findLMax(root->right, leftMax);
    }
    
    void findRMin(TreeNode* root, long* rightMin){
        if(!root)return;
        *rightMin = min(*rightMin, (long)root->val);
        
        findRMin(root->left, rightMin);
        findRMin(root->right, rightMin);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root || !root->left && !root->right)return true;
        
        long leftMax = LONG_MIN;
        long rightMin = LONG_MAX;
        // cout<<leftMax<<" "<<rightMin<<endl;
        findLMax(root->left, &leftMax);
        findRMin(root->right, &rightMin);
        // cout<<"  "<<leftMax<<" "<<rightMin<<endl;
        
        
        if(root->val <= leftMax || root->val >= rightMin)return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};