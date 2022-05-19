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
    ListNode* head;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode();
        head = ptr;
        ListNode* prev = nullptr;
        int c = 0;
        while(l1!= nullptr and l2 != nullptr){
            ptr->next = new ListNode();
            ptr->val = c + l1->val + l2->val;
            
            if(ptr->val > 9){
                int t = ptr->val;
                ptr->val %= 10;
                c = t/10;
            }
            else c = 0;
            
            
            l1 = l1->next;
            l2 = l2->next;
            prev = ptr;
            ptr = ptr->next;
        }
        while(l1!=nullptr){
            ptr->next = new ListNode();
            ptr->val = c + l1->val;
            
            if(ptr->val > 9){
                int t = ptr->val;
                ptr->val %= 10;
                c = t/10;
            }
            else c = 0;
            
            
            l1 = l1->next;
            prev = ptr;
            ptr = ptr->next;
        }
        while(l2!=nullptr){
            ptr->next = new ListNode();
            ptr->val = c + l2->val;
            
            if(ptr->val > 9){
                int t = ptr->val;
                ptr->val %= 10;
                c = t/10;
            }
            else c = 0;
            
            
            l2 = l2->next;
            prev = ptr;
            ptr = ptr->next;
        }
        if(c>0) ptr->val = c;
        else if(prev != nullptr) prev->next = nullptr;
        
        return head;
    }
};