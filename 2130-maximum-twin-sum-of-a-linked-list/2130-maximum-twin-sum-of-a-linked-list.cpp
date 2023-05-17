class Solution {
public:
    ListNode* last = nullptr;
    int n=0;
    int pairSum(ListNode* head) {
        fun(head,nullptr,0);
        int ans=0,i=0;
        while(i<n/2){
            ans = max(ans,head->val+last->val);
            head = head->next;
            last = last->next;
            i++;
        }
        return ans;
    }
    void fun(ListNode* node,ListNode* prev,int i){
        if(node->next==nullptr){
            last = node;
            last->next = prev;
            n++;
            return;
        }
        n++;
        fun(node->next,node,i+1);
        if(i<n/2) return;
        
        node->next = prev;
    }
};