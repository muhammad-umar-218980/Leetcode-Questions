class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)  return false;

        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }

        int remaining = targetSum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};