/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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