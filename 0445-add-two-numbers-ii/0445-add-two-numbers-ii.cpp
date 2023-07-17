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
public:
    ListNode* head;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        rev(l1);ListNode* p1=head;
        rev(l2);ListNode* p2=head;
        
        ListNode* ans=new ListNode();
        ListNode* ptr=ans;
        while(p1 && p2){
            int x=p1->val+p2->val+ptr->val;
            ptr->val = x%10;
            if(x/10 || p1->next || p2->next) ptr->next = new ListNode(x/10);
            ptr=ptr->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1){
            int x=ptr->val + p1->val;
            ptr->val = x%10;
            if(x/10 || p1->next) ptr->next = new ListNode(x/10);
            p1=p1->next;
            ptr=ptr->next;
        }
        while(p2){
            int x=ptr->val + p2->val;
            ptr->val = x%10;
            if(x/10 || p2->next) ptr->next = new ListNode(x/10);
            p2=p2->next;
            ptr=ptr->next;
        }
        rev(ans);
        return head;
    }
    ListNode* rev(ListNode* ptr){
        if(ptr->next==nullptr){
            head=ptr;
            return ptr;
        }
        
        ListNode* x=rev(ptr->next);
        x->next=ptr;
        ptr->next=nullptr;
        return ptr;
    }
};