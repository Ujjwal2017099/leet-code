
class Solution {
    ListNode* root;
    bool f;
public:
    void palindrome(ListNode* ptr,ListNode* prev){
        if(ptr == nullptr) return;
        
        palindrome(ptr->next,ptr);
        if(root->val != ptr->val){f = false;return;}
        root = root->next;
    }
    bool isPalindrome(ListNode* head) {
        root = head;
        f = true;
        ListNode* prev = nullptr;
        palindrome(head,prev);
        return f;
    }
};