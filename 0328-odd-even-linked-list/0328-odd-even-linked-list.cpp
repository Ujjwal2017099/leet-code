
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
        }
        odd->next = t;
        return head;
    }
};