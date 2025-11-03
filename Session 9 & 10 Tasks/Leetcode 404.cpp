class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = 0;

        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                sum = sum + root->left->val;
            }
        }

        sum = sum + sumOfLeftLeaves(root->left);
        sum = sum + sumOfLeftLeaves(root->right);

        return sum;
    }
};
