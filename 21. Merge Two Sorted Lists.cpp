/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    key take away:
        use of pointers
        create a pointer that contains the address of the result
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode l_res(0);
        ListNode* temp = &l_res;
        
        
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2 ->val){
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            } 
            else if (l2->val < l1 ->val){
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            }
        }
        
        if (l1 == NULL){
            temp -> next = l2;
        } 
        else if (l2 == NULL) {
            temp -> next = l1;
        }
        
        return l_res.next;
    }
};