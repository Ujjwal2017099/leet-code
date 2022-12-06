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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* t = even;
        
        while(even){
            odd->next = even->next;
            if(odd->next) odd = odd->next;
             even->next = odd->next;
             even = even->next;
            // if(!(even->next)) odd->next = t;
        }
        odd->next = t;
        return head;
    }
};