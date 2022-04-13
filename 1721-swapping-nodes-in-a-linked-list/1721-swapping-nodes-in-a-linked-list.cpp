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
    ListNode* swapNodes(ListNode* head, int k) {
        int i = 1;
        int temp ;
        ListNode* ptr = head;
        while(ptr != NULL)
        {
            if(i == k)
            {
                temp = ptr->val;
            }
            i++;
            ptr = ptr->next;
        }
        
        int last = i - k;
        ptr = head;
        i = 1;
        while(ptr != NULL)
        {
            if(last == i)
            {
                int temp2 = temp;
                temp = ptr->val;
                ptr->val = temp2;
            }
            i++;
            ptr = ptr->next;
        }
        ptr = head;
        i =1;
        while(ptr!= NULL)
        {
            if(i == k)
            {
                ptr->val = temp;
                return head;
            }
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};