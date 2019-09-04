/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse_k_node(ListNode* &head, int k){
        ListNode* res = new ListNode(head->val);
        head = head->next;
        int count = 1;
        while (count < k){
            ListNode* temp = new ListNode(head->val);
            temp->next = res;
            res = temp;
            head = head->next;
            count++;
        }
        return res;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        ListNode result(0);
        ListNode* tmp = &result;
        int start = 1, end = 1;
        while(head){
            
            if (start != m && end != n) {
                tmp->next = new ListNode(head->val);
                start++;
                end++;
                tmp = tmp->next;
                head = head->next;
            } else if (start == m && end != n){
                tmp->next = reverse_k_node(head, n-m+1);
                end = n;
            } else if (start == m && end == n) {
                while(tmp->next){
                    tmp = tmp->next;  
                } 
                tmp->next = head;
                break;
            }
        }
        return result.next;
    }
};