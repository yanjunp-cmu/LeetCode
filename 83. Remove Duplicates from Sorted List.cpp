/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode result(INT_MAX);
        ListNode* tmp = &result;
        
        if(!head)
            return NULL;
        
        while(head){
            if (head->val == tmp->val){
                head = head->next;
            } else {
                tmp->next = new ListNode(head->val);
                tmp = tmp->next;
                head = head->next;
            }
        }

        return result.next;
    }
};