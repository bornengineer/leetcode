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
    // bool dfs(TreeNode* root, int x){
    //     if(!root)return false;
    //     if(x < root->val)return dfs(root->left, x);
    //     else if(x > root->val)return dfs(root->right, x);
    //     else return true;
    // }
// private: 
    void inorder(TreeNode* root, vector<int>& inorderArr){
        if(!root)return;
        
        inorder(root->left, inorderArr);
        inorderArr.push_back(root->val);
        inorder(root->right, inorderArr);       
    }    
    
    bool findTarget(TreeNode* root, int k) {
        // if(!root || !root->left && !root->right)return false;

        vector<int> inorderArr;
        inorder(root, inorderArr);
        
        int i = 0 , j = inorderArr.size()-1;
        while(i<j){
            if(inorderArr[i]+inorderArr[j] > k)j--;
            else if(inorderArr[i]+inorderArr[j] < k)i++;
            else return true;
        }
        return false;
    }
};
//         if(!root || !root->left && !root->right)return false;
//         int x = k - root->val;
//         if(dfs(root->left, x) || dfs(root->right, x))return true;
        
//         return findTarget(root->left, k) || findTarget(root->right, k);