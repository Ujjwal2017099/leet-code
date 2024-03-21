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
    ListNode* reverseList(ListNode* head) {
        
        if(head==nullptr) return head;
       return fun(head,nullptr);
        
    }
    ListNode* fun(ListNode* node,ListNode* prev){
        if(node->next == nullptr){
            node->next = prev;
            return node;
        }
        
        ListNode* x = fun(node->next,node);
        
        node->next = prev;
        
        return x;
    }
};