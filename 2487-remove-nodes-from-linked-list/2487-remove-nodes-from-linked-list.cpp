
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        return fun(head,nullptr);
    }
    ListNode* fun(ListNode* head,ListNode* prev){
        if(head->next==nullptr){
            return head;
        }
        ListNode* x = fun(head->next,head);
        if(head->val < x->val){
            if(prev)prev->next = x;
            return x;
        }
        return head;
    }
};