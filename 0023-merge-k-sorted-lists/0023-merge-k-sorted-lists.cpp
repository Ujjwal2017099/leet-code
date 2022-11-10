class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return fun(lists,0,lists.size()-1);
    }
    ListNode* merge(ListNode* p1,ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        
        if(p1->val<=p2->val){
            p1->next = merge(p1->next,p2);
            return p1;
        }else{
            p2->next = merge(p1,p2->next);
            return p2;
        }
    }
    ListNode* fun(vector<ListNode*>& l,int left,int right){
        if(left >= right){
            return l[right];
        }
        
        int mid = (left+right)/2;
        ListNode* p1 = fun(l,left,mid);
        ListNode* p2 = fun(l,mid+1,right);
        
        return merge(p1,p2);
    }
};