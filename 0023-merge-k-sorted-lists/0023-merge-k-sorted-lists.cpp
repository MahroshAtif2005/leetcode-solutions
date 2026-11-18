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

    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
           return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //priority queue min heap
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        
        //insert the head of every linked list in pq
        for(auto head: lists){
            if(head!=nullptr){
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            if(node->next != nullptr){
                pq.push(node->next);
            }

            tail->next = node;
            tail = tail->next;
        }
       
       return dummy.next;
        
    }
    
};