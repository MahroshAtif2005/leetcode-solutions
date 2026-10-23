/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* ,Node*> mp;
        Node* curr = head;

        while(curr!=nullptr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr!=nullptr){
          mp[curr]->next = curr->next ? mp[curr->next] : nullptr;
          mp[curr]->random = mp[curr->random] ? mp[curr->random] : nullptr;

          curr = curr->next;
        }
         
        if (head == nullptr) {
           return nullptr;
               }

        return mp[head];
    }
};