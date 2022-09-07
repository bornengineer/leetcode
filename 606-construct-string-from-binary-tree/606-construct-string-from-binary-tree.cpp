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
    string tree2str(TreeNode* root) {
        string res = "";
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, string& res){
        if(!root)return;
        
        res += to_string(root->val);
        
        if(root->left){
            res += "(";
            helper(root->left, res);
            res += ")";
        }else if(root->right) res += "()";
    
        if(root->right){
            res += "(";
            helper(root->right, res);
            res += ")";
        }
    }
    
    
// First solution
/*    
    string tree2str(TreeNode* root) {
        string s = to_string(root->val);
        
        if(root->left){
            s += "(" + tree2str(root->left) + ")";
        }
        
        if(root->right){
            if(!root->left) s += "()";
            
            s += "(" + tree2str(root->right) + ")";
        }
        
        return s;
    }
*/
};