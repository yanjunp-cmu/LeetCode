/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * Merge Sort
 *  separate the incoming vector using binary search
 *  stopping criteria: start >= end
 *  
 */
class Solution {
private:    
    ListNode* mergehelper(vector<ListNode*>& lists, int start, int end){
        if (start >= end) return lists[start];
        
        // divide and conqueror
        int mid = start + (end - start)/2;
        ListNode* left = mergehelper(lists, start, mid);
        ListNode* right = mergehelper(lists, mid + 1, end);
        
        // initialize a dummy head
        ListNode result(0);
        ListNode* tmp = &result;
        // merge sort until one is out
        while(left && right){
            if (left->val <= right->val){
                tmp -> next = new ListNode(left->val);
                left = left->next;
                tmp = tmp -> next;
            } else {
                tmp -> next = new ListNode(right->val);
                right = right->next;
                tmp = tmp -> next;
            }
        }
        // merge left over into the result
        if (left) {
            tmp->next = left;
        } else if (right) {
            tmp->next = right;
        }
        
        return result.next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        return mergehelper(lists, 0, lists.size()-1);
    }
};