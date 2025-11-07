class Solution {
public:
    bool helper(TreeNode* root , TreeNode* min , TreeNode* max){
        if(root == nullptr) return true;

        if(min != nullptr and root->val<=min->val) return false;

        if(max != nullptr and root->val>=max->val) return false;

        bool leftHelper = helper(root->left,min,root);
        bool rightHelper = helper(root->right,root,max);

        return leftHelper and rightHelper;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,nullptr,nullptr);
    }
};