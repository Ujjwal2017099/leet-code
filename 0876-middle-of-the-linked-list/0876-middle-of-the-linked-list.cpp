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
    int mid = -1;
    ListNode* md = nullptr;
    ListNode* middleNode(ListNode* head) {
        fun(head,nullptr,1);
        return md;
    }
    void fun(ListNode* node,ListNode* prev,int s){
        if(!node->next){
            mid = s&1 ? (s+1)/2 : s/2 + 1;
            if(mid == s) md = node;
            return;
        }
        
        fun(node->next,node,s+1);
        if(mid==s){
            md = node;
        }
    }
};