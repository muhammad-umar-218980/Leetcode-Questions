class Solution {
public:

    void helperFunc(vector<int>& nums, int idx ,set<vector<int>> &ans){
        int n = nums.size();
        if(idx == n){
            ans.insert(nums);
            return;
        }

        for(int i = idx ; i <n;i++){
            swap(nums[i],nums[idx]);
            helperFunc(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        helperFunc(nums, 0 , ans);
        vector<vector<int>> answer(ans.begin(),ans.end());
        return answer;
    }
};