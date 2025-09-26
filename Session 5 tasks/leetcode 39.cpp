class Solution {
public:

    void helperFunc(vector<int>& candidates, int idx, int target, vector<vector<int>> &ans, vector<int>& combination) {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (idx == candidates.size() || target < 0) {
            return;
        }

        combination.push_back(candidates[idx]);
        helperFunc(candidates, idx, target - candidates[idx], ans, combination);  
        combination.pop_back();

        helperFunc(candidates, idx + 1, target, ans, combination);  
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        helperFunc(candidates, 0, target, ans, combination);
        return ans;
    }
};
