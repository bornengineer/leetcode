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
    // #1 Approach O(n^2) cause we are calculating leftMax & rightMin in each recursive call
//     void findLMax(TreeNode* root, long* leftMax){
//         if(!root)return;
//         *leftMax = max(*leftMax,(long)root->val);
        
//         findLMax(root->left, leftMax);
//         findLMax(root->right, leftMax);
//     }
    
//     void findRMin(TreeNode* root, long* rightMin){
//         if(!root)return;
//         *rightMin = min(*rightMin, (long)root->val);
        
//         findRMin(root->left, rightMin);
//         findRMin(root->right, rightMin);
//     }
    
//     bool isValidBST(TreeNode* root) {
//         if(!root)return true;
        
//         long leftMax = LONG_MIN; // using long to handle [-2147483648,null,2147483647]
//         long rightMin = LONG_MAX;
//         findLMax(root->left, &leftMax);
//         findRMin(root->right, &rightMin);
                
//         if(root->val <= leftMax || root->val >= rightMin)return false;
        
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
    
    
    // #2 Aproach is about sending all the variables ie min, max & isBST of both left & right in each rescursive call to save the time from O(n^2)(from approach #1) to O(n)
    // here we can use pair<pair<int,int>,int> or a isBST class to return 3 properties
    
    
    // #3 Approach by just going from top to down and maniputing the ranges
    // TC same as approach #2 ie O(n)
    // here typecasting to "long" to handle [-2147483648,null,2147483647] & [2147483647]
    bool isValidBST(TreeNode* root, long min = INT_MIN, long max = INT_MAX){
        if(!root)return true;
        
        if((long)root->val < min || (long)root->val > max)return false;
        
        bool isLeftOk = isValidBST(root->left, min, (long)root->val-1);
        bool isRightOk = isValidBST(root->right, (long)root->val+1, max);
        return isLeftOk && isRightOk;
    }
};

        // cout<<leftMax<<" "<<rightMin<<endl;
        // cout<<"  "<<leftMax<<" "<<rightMin<<endl;