/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        //already cloned this node
        if(copies.contains(node)){
            return copies[node];
        }
        //create a new copy
        Node* copy = new Node(node->val);
        //remember that we cloned it
        copies[node]=copy;

        //clone all its neighbours
        for(Node* neighbor: node->neighbors){
            copy->neighbors.push_back(cloneGraph(neighbor));   
                 }
                 return copy;
    }
};