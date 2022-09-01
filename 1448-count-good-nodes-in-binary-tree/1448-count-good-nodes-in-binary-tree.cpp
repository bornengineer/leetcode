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
    void helper(TreeNode* root, int* cnt, int temp){
        if(!root)return;
        
        if(root->val >= temp){
            *cnt += 1;
        }
        temp = max(temp,root->val);
        // cout<<*cnt<<" "<<temp<<endl;
        
        helper(root->left, cnt, temp);
        helper(root->right, cnt, temp);
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int temp = INT_MIN;
        helper(root, &cnt, temp);
        // cout<<endl;
        return cnt;
    }
};