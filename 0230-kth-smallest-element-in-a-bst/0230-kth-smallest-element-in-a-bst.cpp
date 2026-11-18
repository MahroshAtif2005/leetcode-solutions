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
        inorder(root,answer,count,k);
        return answer;
    }

    void inorder(TreeNode* node,int& answer,int& count,int k){
        
        if (node==nullptr){
            return;
        }

        inorder(node->left,answer,count,k);
        
        count++;
        if(count==k){
            answer = node->val;
        }

        inorder(node->right,answer,count,k);
    }
};