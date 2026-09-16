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

    bool valid(TreeNode* node, long long minimum, long long maximum){
        if (node==nullptr){
            return true;
        }
        //current node must be inside its allowed range
        if(node->val<=minimum || node->val>=maximum){
            return false;
        }
        //check both subtrees
        return valid(node->left,minimum,node->val) && valid(node->right,node->val,maximum);
    }
    bool isValidBST(TreeNode* root) {
        //dfs 
        //everything left of subtree should be less than root
        //and everything at right of subtree should be more than root and so on
        //What RANGE of values is this node allowed to have?
     return valid(root,LLONG_MIN,LLONG_MAX);
    }
};