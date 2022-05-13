
class Solution {
    ListNode* newptr;
public:
    void reverse(ListNode* ptr,ListNode* prev){
        if(ptr == nullptr) return;
        
        ListNode* temp = ptr->next;
        reverse(temp,ptr);
        
        if(!newptr) newptr = ptr;
        
        ptr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        newptr = nullptr;
        ListNode* prev = nullptr;
        reverse(head,prev);
        
        return newptr;
    }
};