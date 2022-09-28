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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp -> next;
            cnt++;
        }
        
        int k = 0;
        ListNode *temp2 = new ListNode;
        temp2 -> next = head;
        ListNode *temp3 = temp2;
        while(cnt - k != n){
            temp3 = temp3 -> next;
            k++;
        }
        temp3 -> next = temp3 -> next -> next;

        return temp2 -> next;
    }
};