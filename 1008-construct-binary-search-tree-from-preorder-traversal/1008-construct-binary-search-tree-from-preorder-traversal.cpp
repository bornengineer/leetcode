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
    TreeNode* helper(vector<int>& preorder, int left, int right){
        if(left > right)return NULL;
        
        TreeNode* root = new TreeNode(preorder[left]);

        int pos = left+1;
        while(pos <= right && preorder[pos] < root->val )pos++;
        
        root->left = helper(preorder, left+1, pos-1);
        root->right = helper(preorder, pos, right);

        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int left = 0;
        int right = n - 1;
        return helper(preorder, left, right);
    }
    
};
        
        // cout<<left<<" "<<pos<<" "<<right<<endl;
        
        
//         if(i == preorder.size())return NULL;
        
//         TreeNode* root = new TreeNode(preorder[i++]);
        
//         if(root->val < preorder[0]) root->left = bstFromPreorder(preorder);
        
//         else if(root->val > preorder[0]) root->right = bstFromPreorder(preorder);
        
//         else {
//             root->left = bstFromPreorder(preorder);
//             root->right = bstFromPreorder(preorder);
//         }
//         return root;
// private: 
//     int i = 0;