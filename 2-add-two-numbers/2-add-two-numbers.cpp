class Solution {
    ListNode* head;
    ListNode* ptr;
    ListNode* prev;
    ListNode* c1;
    ListNode* c2;
    int c;
public:
    Solution(){
        ptr = new ListNode();
        head = ptr;
        prev = nullptr;
        c1 = nullptr;
        c2 = nullptr;
        c=0;
    }
    void add(ListNode* &l1, ListNode* &l2){
        c1 = l1;
        c2 = l2;
        if(l1== nullptr or l2 == nullptr) return;
        
        
        ptr->next = new ListNode();
        ptr->val = c + l1->val + l2->val;
        
        if(ptr->val > 9){
            int t = ptr->val;
            ptr->val %= 10;
            c = t/10;
        }
        else c = 0;
        
        prev = ptr;
        ptr = ptr->next;
        
        add(l1->next,l2->next);
    }
    void addone(ListNode* &l1){
        if(l1 == nullptr) return;
        
        ptr->next = new ListNode();
        ptr->val = c + l1->val;
        
        if(ptr->val > 9){
            int t = ptr->val;
            ptr->val %= 10;
            c = t/10;
        }
        else c = 0;
        
        prev = ptr;
        ptr = ptr->next;
        
        addone(l1->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        add(l1,l2);
        addone(c1);
        addone(c2);
        if(c>0) ptr->val = c;
        else if(prev != nullptr) prev->next = nullptr;
        return head;
    }
};