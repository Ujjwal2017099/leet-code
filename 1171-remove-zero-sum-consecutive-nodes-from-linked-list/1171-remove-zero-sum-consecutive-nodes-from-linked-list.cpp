
class Solution {
public:
    ListNode* t = new ListNode(1e7);
    ListNode* removeZeroSumSublists(ListNode* h) {
        t->next = h;
        bool f=1;
        
        fun( h,1e7,t);
        
        return t->next;
    }
    void fun(ListNode* ptr,int sm,ListNode* prev){
        if(!ptr) return;
        
        int x = ptr->val;
        int nxt_sm=sm;
        ListNode* temp = prev;
        bool f=0;
        while(sm+x!=0 && temp){
            sm-=temp->val;
            if(f) prev=prev->next;
            temp=temp->next;
            f=1;
        }
        if(sm+x==0){
            prev->next=ptr->next;
            nxt_sm -= sm; 
        }else{
            nxt_sm+=x;
        }
        fun(ptr->next,nxt_sm,t);
    }
};