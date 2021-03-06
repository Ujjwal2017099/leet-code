class Solution {
    ListNode* root;
    ListNode* ptr;
public:
    Solution(){
        root = nullptr;
        ptr = nullptr;
    }
    void remove(ListNode* head, int val){
        if(head == nullptr) return;
        if(head->val == val){remove(head->next,val); return;}
        
        ListNode* p = new ListNode(head->val);
        if(ptr == nullptr){
            ptr = p;
            root = ptr;
            remove(head->next,val);
        }
        else{
            ptr->next = p;
            ptr = ptr->next;
            remove(head->next,val);
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        
        remove(head,val);
        
        return root;
    }
};