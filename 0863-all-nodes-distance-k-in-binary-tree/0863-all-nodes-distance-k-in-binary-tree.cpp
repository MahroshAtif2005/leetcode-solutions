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
    void buildParent(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == nullptr)
            return;
        if (root->left) {
            parent[root->left] = root;
            buildParent(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            buildParent(root->right, parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr) {
            return {};
        }
        // lets create a parent map
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, parent);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;
        while (!q.empty() && distance < k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                vector<TreeNode*> neighbors = {node->left, node->right,
                                               parent.count(node) ? parent[node]
                                                                  : nullptr};

               for (TreeNode* next : neighbors) {
                    if (next != nullptr && !visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            distance++;
        }
        vector<int> answer;
        while (!q.empty()) {
            answer.push_back(q.front()->val);
            q.pop();
        }
        return answer;
    }
};