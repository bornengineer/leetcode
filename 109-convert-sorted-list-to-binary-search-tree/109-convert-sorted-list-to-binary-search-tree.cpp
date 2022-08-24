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
    TreeNode* traverse (ListNode* head){
        if(!head)return NULL;
        
        if(!head->next){ // wrote this case to handle the case where only head remains
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
        
        // creating dummy to initialize slow one before the head to get the pointer one before the mid
        ListNode *dummy = new ListNode;  
        dummy -> next = head;
        ListNode *slow = dummy;
        ListNode* fast = head;
            
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
                    
        ListNode* mid = slow->next; // mid will be the next node to slow which will be the treenode value
        slow->next = NULL; // terminating head pointer by putting null in slow next
        TreeNode* node = new TreeNode(mid->val);
        mid = mid->next;
        
        node->left = traverse(head); // calling one both left & right with both the divided linked-lists 
        node->right = traverse(mid);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return traverse(head);
    }
};