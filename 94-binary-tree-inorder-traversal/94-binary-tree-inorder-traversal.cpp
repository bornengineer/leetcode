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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
           
    
    vector<int> ret;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(!root)return {};
    //     inorderTraversal(root->left);
    //     ret.push_back(root->val);
    //     inorderTraversal(root->right);
    //     return ret;
    // }
    
//  iterative using stack (idea by - jianchao-li)
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root)return {};
//         vector<int> ret;
//         stack<TreeNode*> st;
//         while(root || !st.empty()){
//             while(root){
//                 st.push(root);
//                 root = root -> left;
//             }
//             root = st.top();
//             st.pop();
//             ret.push_back(root->val);
//             root = root -> right;
//         }
//         return ret;
//     }
};


    // iterative using stacks by jianchao-li
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> nodes;
    //     stack<TreeNode*> todo;
    //     while (root || !todo.empty()) {
    //         while (root) {
    //             todo.push(root);
    //             root = root -> left;
    //         }
    //         root = todo.top();
    //         todo.pop();
    //         nodes.push_back(root -> val);
    //         root = root -> right;
    //     }
    //     return nodes;
    // }