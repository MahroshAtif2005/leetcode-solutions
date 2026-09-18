/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         vector<int> answer;
         traverse(root,0,answer); 
         return answer;
    }
    void traverse(TreeNode* node,int depth,vector<int>& answer){
     if(node==nullptr){
        return;
     }
     // Only add if this is a NEW depth
     if(depth == answer.size()){
        answer.push_back(node->val);
     }
     //Right first
     traverse(node->right,depth+1,answer);
     //Left second
     traverse(node->left,depth+1,answer);
    }
    
};