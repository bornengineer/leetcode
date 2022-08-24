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
    
    TreeNode* traverse(vector<int>& nums, int s, int e){
        if(s > e)return NULL;
        int mid = (s+e)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traverse(nums, s, mid-1);
        node->right = traverse(nums, mid+1, e);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        return traverse(nums, s, e);
    }
};