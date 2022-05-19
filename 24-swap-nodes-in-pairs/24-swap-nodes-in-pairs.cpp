class Solution {
    ListNode* prev;
public:
    Solution(){
        prev = nullptr;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode* curr = head;
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        if(prev != nullptr) prev->next = temp;
        prev = curr;
        swapPairs(curr->next);
        return temp;
    }
};