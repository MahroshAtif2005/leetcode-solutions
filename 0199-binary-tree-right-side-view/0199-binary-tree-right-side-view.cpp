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

    void traverse(TreeNode* root, int depth, vector<int>& answer){
        if(root == nullptr){
            return;
        }

        if(answer.size()==depth){
            answer.push_back(root->val);
        }

        traverse(root->right,depth+1,answer);
        traverse(root->left,depth+1,answer);
  
    }
};