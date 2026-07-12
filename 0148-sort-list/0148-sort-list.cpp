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
    ListNode* merge(ListNode*right, ListNode*left)
    {
        ListNode*head;
        if(!right)return left;
        if(!left)return right;
        if(right->val < left->val){
            head = right;
            right = right->next;
        }
        else{
            head = left;
            left = left->next;
        }
        ListNode*curr = head;
        while(right && left)
        {
            if(right->val < left->val)
            {
                curr ->next = right;
                right = right->next;
            }
            else{
                curr->next = left;
                left = left->next;  
            }
            curr = curr->next;
        }
        if(left)curr->next = left;
        if(right)curr->next = right;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode* l = sortList(head);
        ListNode* r =  sortList(mid);
        return merge(l, r);
    }
};