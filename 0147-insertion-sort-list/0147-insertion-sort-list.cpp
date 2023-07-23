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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans=head;
        while(head){
            ListNode* ptr=head->next;
            ListNode* min=head;
            while(ptr){
                if(ptr->val < min->val) swap(min->val,ptr->val);
                ptr = ptr->next;
            }
            swap(head->val,min->val);
            head = head->next;
        }
        return ans;
    }
};