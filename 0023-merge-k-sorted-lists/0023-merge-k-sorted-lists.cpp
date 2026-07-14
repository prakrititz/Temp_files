class Solution {
public:
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for(auto it: lists) {
            if(it != NULL) {
                pq.push(it);
            }
        }
        
        // Use a dummy node to act as the starting point
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(!pq.empty())
        {
            // 1. Get the smallest node and immediately pop it
            ListNode* x = pq.top();
            pq.pop();
            
            // 2. Attach it to our merged list
            curr->next = x;
            
            // 3. If this node has a next element, push it into the heap
            if(x->next != NULL)
            {
                pq.push(x->next);
            }
            
            // 4. Move our current pointer forward
            curr = curr->next;
        }
        
        // The real merged list starts exactly one node AFTER our fake dummy node
        return dummy->next;
    }
};