/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        if (copies.find(head) == copies.end()){
            copies[head]            = new Node(head->val, NULL, NULL);
            copies[head] -> next    = copyRandomList(head->next);
            copies[head] -> random  = copyRandomList(head->random);
        }
        return copies[head];
    }
};