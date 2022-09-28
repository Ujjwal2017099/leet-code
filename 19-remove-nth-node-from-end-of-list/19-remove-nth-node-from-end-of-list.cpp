
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return fun(head,nullptr,n);
    }
    ListNode* fun(ListNode* ptr,ListNode* prev,int& n){
        if(ptr==nullptr){
            return ptr;
        }
        
        ListNode* nxt = fun(ptr->next,ptr,n);
        if(n==1){
            if(prev==nullptr){
                return ptr->next;
            }
            prev->next = nxt;
        }
        n--;
        return ptr;
    }
};