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
    ListNode* reverseList(ListNode* head) {
       ListNode* prev =nullptr;
       ListNode* curr = head;

       while(curr!=nullptr){
        ListNode* temp = curr->next;//save next

        curr->next=prev; //reverse arrow

        prev=curr; //move prev forward
        curr=temp; //move curr forward
       }
       return prev;
    }
};