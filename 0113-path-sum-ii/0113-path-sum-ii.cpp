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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> arr;
        traverse(root,targetSum,0,arr,answer);
        return answer;
    }
    //traverse each node n keep adding
    void traverse(TreeNode* node, int targetSum,long long sum, vector<int>& arr,vector<vector<int>>& answer){
    
        if(node==nullptr){
            return;
        }
      //add current node
      sum+= node->val;
      arr.push_back(node->val);
      //are we at the leaf and have the target sum
      if(node->left==nullptr && node->right==nullptr && sum==targetSum){
       answer.push_back(arr);
      }
      //explore both branches
      traverse(node->left,targetSum,sum,arr,answer);
      traverse(node->right,targetSum,sum,arr,answer);

      //undo current node before returning
      arr.pop_back();
    }
};