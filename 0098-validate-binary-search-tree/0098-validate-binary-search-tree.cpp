class Solution {
public:
    TreeNode* prev = nullptr;
    bool inorder(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (!inorder(root->left))
            return false;
        if (prev != nullptr && root->val <= prev->val)
            return false;
        prev = root;
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};