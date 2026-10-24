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
       
    
    int maxDepth(TreeNode* root) {
      int maxCount = 0;
      traverse(root,0,maxCount);
      return maxCount;
    }

    void traverse(TreeNode* node, int count, int& maxCount){
      if (node==nullptr){
       return;
      }
      count++;
      maxCount = max(count,maxCount);

      traverse(node->left,count,maxCount);
      traverse(node->right,count,maxCount);
    }

};