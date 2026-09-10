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
    void reorderList(ListNode* head) {
        if (head ==nullptr || head->next==nullptr){
            return;
        }
        //1- find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //2- split and reverse scond half
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        //reversing it
        while(second!=nullptr){
            ListNode* temp = second->next; //save next
            second->next = prev; //reverse arrow
            prev = second; //a new previous
            second = temp;//make tmpt the new current
        }

        //prev is now begininng of reversed second half
        second = prev;

        //3- Merge
        ListNode* first = head;
        while (second!=nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};