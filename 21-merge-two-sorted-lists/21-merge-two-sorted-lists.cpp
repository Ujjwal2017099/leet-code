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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int x;
        if(list1 == nullptr) {
            if(list2 == nullptr) return nullptr;
            
            x = list2->val;
            list2 = list2->next;
        }
        else if(list2 == nullptr){
            x = list1->val;
            list1 = list1->next;
        }
        else if(list1->val < list2->val){x=list1->val;list1 = list1->next;}
        else {x=list2->val ; list2 = list2->next;}
        ListNode* head = new ListNode(x);
        
        ListNode* root = head;
        
        
        while(list1 != nullptr and list2 != nullptr)
        {
            
            if(list1->val < list2->val){x=list1->val;list1 = list1->next;}
            else {x=list2->val ; list2 = list2->next;}
            ListNode* ptr = new ListNode(x);
            
            head->next = ptr;
            head = head->next;
            
        }
        
        while(list1 != nullptr)
        {
            ListNode* ptr = new ListNode(list1->val);
            list1 = list1->next;
            
            head->next = ptr;
            head = head->next;
        }
        
        while(list2 != nullptr)
        {
            ListNode* ptr = new ListNode(list2->val);
            list2 = list2->next;
            
            head->next = ptr;
            head = head->next;
        }
        
        return root;
    }
};