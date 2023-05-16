
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next == nullptr) return head;
        
        ListNode* t = head->next;
        head->next = t->next;
        t->next = head;
        ListNode* ans = t;
        ListNode* curr = head->next;
        ListNode* prev=head;
        
        while(curr && curr->next){
            ListNode* t = curr->next;
            curr->next = t->next;
            t->next = curr;
            prev->next = t;
            prev=curr;
            curr=curr->next;
        }
        return ans;
    }
};