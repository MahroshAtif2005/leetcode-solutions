/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        
        if(p->val < root->val && q->val < root->val){
          return lowestCommonAncestor(root->left,p,q);
        }

        if(p->val > root->val && q->val > root->val){
         return lowestCommonAncestor(root->right,p,q);
        }

        return root;
    }
};

//so if there is a split in the tree at a point, example is in left subtree and q is in right subtree, then that node for sure is the lca