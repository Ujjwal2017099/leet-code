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
    int md = 0;
    ListNode* deleteMiddle(ListNode* head) {
        return fun(head,0);
    }
    ListNode* fun(ListNode* ptr,int n){
        if(ptr==nullptr){
            md = (n)/2;
            return nullptr;
        }
        ptr->next = fun(ptr->next,n+1);
        if(n==md){
            return ptr->next;
        }
        return ptr;
    }
};