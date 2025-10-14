class Solution {
public:
    void helperFunc(vector<int>& nums, vector<int>& current, vector<vector<int>>& answer, int idx) {
        if(idx == nums.size()) {
            answer.push_back(current);
            return;
        }

        current.push_back(nums[idx]);
        helperFunc(nums, current, answer, idx + 1);

        current.pop_back();
        helperFunc(nums, current, answer, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> current;
        helperFunc(nums, current, answer, 0);
        return answer;
    }
};
