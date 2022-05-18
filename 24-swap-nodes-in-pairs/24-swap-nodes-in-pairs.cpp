
class Solution {
    int i;
    ListNode* prev;
public:
    void pair_swap(ListNode* ptr)
    {
        if(ptr == nullptr or ptr->next == nullptr) return;
        if(ptr->next != nullptr and i%2){
            int temp = ptr->next->val;
            ptr->next->val = ptr->val;
            ptr->val = temp;  
        }
        i++;
        pair_swap(ptr->next);
    }
    ListNode* swapPairs(ListNode* head) {
        i = 1;
        pair_swap(head);
        return head;
    }
};