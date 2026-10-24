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
        int count = 0;
        int answer;
        inorder(root,count,answer,k);
        return answer;
    }
    void inorder(TreeNode* node, int& count,int& answer, int k){
        if(node==nullptr){
            return;
        }

        inorder(node->left, count,answer, k);

        count++;
        if(count == k){
            answer = node->val;
            return;
        }

        inorder(node->right, count,answer, k);
    }
};