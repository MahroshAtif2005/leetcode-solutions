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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> answer;

      if(root == nullptr){
        return answer;
      }

      queue<TreeNode*> q;

      q.push(root);

      while(!q.empty()){
        int levelSize = q.size();
        vector<int> levels;
        for(int i = 0; i<levelSize; i++){
            TreeNode* node = q.front();
            q.pop();
            levels.push_back(node->val);
            if(node->left != nullptr){
            q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        answer.push_back(levels);
      }
      return answer;
    }
};