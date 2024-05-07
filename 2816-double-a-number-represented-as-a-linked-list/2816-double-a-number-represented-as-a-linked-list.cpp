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
    ListNode* doubleIt(ListNode* head) {
        int x=0;
        if(head->next) x = fun(head->next);
        int y = 2*head->val + x;
        // cout<<head->val;
        head->val = y%10;
        
        y=y/10;
        ListNode* node = head;
        while(y){
            // cout<<"a";
            ListNode* temp = new ListNode(y%10,node);
            y = y/10;
            node = temp;
        }
        return node;
    }
    int fun(ListNode* node){
        if(node->next==nullptr) {
            int x = 2*node->val;
            node->val = x%10;
            return x/10;
        }
        
        int x = fun(node->next);
        int y = 2*node->val + x;
        
        node->val = y%10;
        
        return y/10;
    }
};