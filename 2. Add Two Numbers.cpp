/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Pay Attention to overflow case when either ListNode is NULL
    use of pointer and reference!
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        
        ListNode result(0);
        ListNode* tmp = &result;
        
        int carry = 0;
        
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            if (sum < 10) {
                tmp->next = new ListNode(sum);
                carry = 0;
            }
            else {
                tmp->next = new ListNode(sum - 10);
                carry = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
            tmp = tmp->next;
        } 
        
        if(!l1 && l2){
            while (l2){
                int sum = l2->val + carry;
                if (sum < 10) {
                    tmp->next = new ListNode(sum);
                    carry = 0;
                }
                else {
                    tmp->next = new ListNode(sum - 10);
                    carry = 1;
                }
                l2 = l2->next;
                tmp = tmp->next;
            }
            if (carry) tmp->next = new ListNode(carry);
        } else if (!l2 && l1) {
            while (l1){
                int sum = l1->val + carry;
                if (sum < 10) {
                    tmp->next = new ListNode(sum);
                    carry = 0;
                }
                else {
                    tmp->next = new ListNode(sum - 10);
                    carry = 1;
                }
                l1 = l1->next;
                tmp = tmp->next;
            }
            if (carry) tmp->next = new ListNode(carry);
        } else {
            if (carry) tmp->next = new ListNode(carry);
        }
        
        return result.next;
    }
};