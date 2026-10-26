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
    int kthSmallest(TreeNode* root, int k) {
       //binary search tree -> so do inorder traversal
       int answer;
       int count = 0;
       inorder(root,k,answer,count);
       return answer;
    }
    void inorder(TreeNode* node, int k, int& answer,int& count){
       if(node == nullptr){
        return;
       }

       inorder(node->left,k,answer,count);
       
       count++;
       if(count == k){
        answer = node->val;
        return;
       }

       inorder(node->right,k,answer,count);
    }
};