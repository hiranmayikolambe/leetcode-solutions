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
        vector<int> values;
        inordertraversal(root, values);
        int k_smallest = values[k-1];
        return k_smallest;
    }
    void inordertraversal(TreeNode* node, vector<int>& values){
        if (node){
            inordertraversal(node->left, values);
            values.push_back(node->val);
            inordertraversal(node->right, values);
        }
    }
};