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
    bool f=1;
    void deleteNode(ListNode* node) {
        if(node->next==nullptr){
            return;
        }
        node->val = node->next->val;
        deleteNode(node->next);
        if(f){
            node->next=nullptr;
            f=0;
        }
    }
};