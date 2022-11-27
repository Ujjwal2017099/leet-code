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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* ptr = head;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        vector<int> ans;
        int mx = INT_MIN;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>=mx){
                ans.push_back(v[i]);
            }
            mx = max(v[i],mx);
        }
        // cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        if(ans.size()){
            ListNode* ptr = new ListNode(ans[0]);
            ListNode* t = ptr;
            for(int i=1;i<ans.size();i++){
                t->next = new ListNode(ans[i]);
                t = t->next;
            }
            return ptr;
        }
        
        return nullptr;
    }
};