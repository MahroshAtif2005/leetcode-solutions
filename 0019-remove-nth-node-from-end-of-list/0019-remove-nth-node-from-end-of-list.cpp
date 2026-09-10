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
 /*
 1 → 2 → 3 → 4 → 5
n = 2

The 2nd node from the end is 4.

Now put fast at the last node, 5.

Ask yourself: if I go 2 steps backwards from fast, where do I land?
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode dummy(0);
      dummy.next = head;
      ListNode* slow = &dummy;
      ListNode* fast = & dummy;

      for (int i = 0; i<n;i++){
        fast = fast->next;
      }

      while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;

      return dummy.next;
    }
};