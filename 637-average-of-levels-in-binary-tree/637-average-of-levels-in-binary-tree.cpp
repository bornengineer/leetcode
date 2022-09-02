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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        vector<double> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i = 0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ret.push_back(sum/size);
        }        
        return ret;
    }
};


// unnecessary long approach by first building a 2D vector & then saving it's avg to a vector
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//         if(!root)return {};
//         vector<vector<int>> levels;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             vector<int> temp;
//             for(int i = 0 ; i<size ; i++){
//                 TreeNode* front = q.front();
//                 q.pop();
//                 temp.push_back(front->val);
//                 if(front->left){
//                     q.push(front->left);
//                 }
//                 if(front->right){
//                     q.push(front->right);
//                 }
//             }
//             levels.push_back(temp);
//         }
        
//         vector<double> ret;
//         for(int i = 0 ; i<levels.size(); i++){
//             int size = levels[i].size();
//             double sum = 0;
//             for(int j = 0; j<size; j++){
//                 sum += levels[i][j];
//             }
//             ret.push_back(sum/size);
//         }
        
//         return ret;
//     }
// };