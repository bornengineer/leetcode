/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* dfs (ListNode* head){
        if(!head)return NULL;
        TreeNode* node = new TreeNode;
        ListNode* mid = new ListNode;
        
        if(!head->next){
            ListNode* slow = head;
            node = new TreeNode((slow->val));
            head = NULL;
            mid = NULL;
        }
        else{
            ListNode *dummy = new ListNode;
            dummy -> next = head;
            ListNode *slow = dummy;
            ListNode* fast = head;
            
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
                    
            mid = slow->next;
            slow->next = NULL;
            node = new TreeNode((mid->val));
            mid = mid->next;
        }
        // cout<<"fast-slow: "<<fast->val<<" "<<slow->val<<endl;
        
        
        // if(!head->next)head = NULL;
        // if(!mid-)mid = NULL;
        // cout<<head->val<<" "<<mid->val<<endl;
        
        node->left = dfs(head);
        node->right = dfs(mid);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head);
    }
};