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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==nullptr || head->next==nullptr || k==0){
        return head;
       }

       int size =0;
       ListNode* tail = head;

       //find size and teh tail
       while(tail->next!=nullptr){
        tail=tail->next;
        size++;
       }
       
       size++;

       k=k%size;

       if (k==0){
        return head;
       }

       //make the list circular
       tail->next=head;
        
       int stepsToNewTail =size-k-1;
       ListNode* newTail = head;

       for (int i =0; i<stepsToNewTail ;i++){
           newTail = newTail->next;
       }

       ListNode* newHead = newTail->next;
       //break the cycle
       newTail->next =nullptr;

       return newHead;
    }
};