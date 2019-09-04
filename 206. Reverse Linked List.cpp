/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
	Recursion
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

/*
	Iteration
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (!head) return NULL;
        ListNode* result = new ListNode(head->val);
        head = head->next;
        while(head){
        	ListNode* tmp = new ListNode(head->val);
        	tmp->next = result;
        	result = tmp;

        	head = head->next;
        }
        return result;
    }
};